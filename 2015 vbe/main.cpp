#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char CDfv[] = "U1.txt";
const char CRfv[] = "U1rez.txt";
const int CMax = 20;
string avis;

struct Avis{
    string ru;
    char Dnr[CMax];
    int sut = 0;  // sutamapa
};

void nuskaitymas(Avis A[], int & n, int & il, int & ind){
    ifstream fd(CDfv);
    char pav[CMax / 2 + 1];
    fd >> n >> il >> ind;
    for(int x = 0; x < n; x++){
        fd.ignore(80, '\n');
        fd.get(pav, CMax / 2 + 1);
        A[x].ru = pav;
        for(int i = 0; i < il; i++)
            fd >> A[x].Dnr[i];
    }
}

void tikrinti(Avis A[], int n, int il, int ind){
    int sum;
    for(int x = 0; x < n; x++){
        sum = 0;
        for(int i = 0; i < il && x != ind - 1; i++){
            if(A[ind - 1].Dnr[i] == A[x].Dnr[i])
                sum++;
            A[x].sut = sum;
        }
    }
}

void rikituoti(Avis A[], int n, int il, int ind){
    Avis ats;
    for(int x = 0; x < n - 1; x++){
        for(int i = x + 1; i < n; i++){
            if((A[x].sut < A[i].sut) || (A[x].sut == A[i].sut && A[x].ru > A[i].ru)){
                ats = A[x];
                A[x] = A[i];
                A[i] = ats;
            }
        }
    }
}

int main()
{
    Avis A[CMax]; int n;
    int il, ind;
    ofstream fr (CRfv);
    nuskaitymas(A, n, il, ind);
    fr << A[ind - 1].ru << endl;
    avis = A[ind - 1].ru;
    tikrinti(A, n, il, ind);
    rikituoti(A, n, il, ind);
    for(int x = 0; x < n; x++){
        if(A[x].ru != avis)
            fr << A[x].ru << " " << A[x].sut << endl;
    }
    return 0;
}
