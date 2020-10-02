#include <iostream>
#include <fstream>

using namespace std;
struct komanda {

string pav;
double ugis;
int taskai;


};
const char CDfv[] = "duomenys.txt";
const char CRfv[] = "rezai.txt";
const int Cmax = 100;

void nuskaityti (komanda A[], int & n, int & p, int & k)
{


    ifstream fd (CDfv);
    fd >> n;
    for (int i = 0; i < n; i++)
    {

       fd >> A[i].pav >> A[i].ugis >> A[i].taskai;



    }
    fd >> p >> k;
    fd.close();


}
void atrinkti(komanda A[], komanda B[], int n, int k, int p, int & m)
{



     int max = A[0].ugis;
    for(int i = 0; i < n; i++)
    {

        if (A[i].ugis > max)
            max = A[i].ugis;


    }

    int makstaskai = A[0].taskai;
    for(int i = 0; i < n; i++)
    {

        if (A[i].taskai > max)
            makstaskai = A[i].taskai;


    }



    m = 0;
    for(int i = 0; i < n; i++)
    {

        if (A[i].ugis >= max-(max*p/100)|| A[i].taskai >= makstaskai-(makstaskai*k/100))
           {

            B[m] = A[i];
            m++;
            }


    }


}
void spausdinti(komanda B[], int m)
{

    ofstream fr(CRfv);
    fr << "vardas   " << "ugis"<< endl;
    for(int i = 0; i < m; i++)
 fr << B[i].pav <<" "<< B[i].ugis << " " << B[i].taskai << endl;
    fr.close();

}

int main()
{
    komanda A[Cmax]; int n; int k, p; int m;
    komanda B[Cmax];
    nuskaityti(A,n,p,k);
    atrinkti(A,B,n,k,p,m);
    spausdinti(B,m);






    return 0;
}
