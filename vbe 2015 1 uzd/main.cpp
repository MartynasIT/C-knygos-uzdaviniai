#include <iostream>
#include <fstream>

using namespace std;
const int cmax = 20;
const char CDfv[] = "duomenys.txt";
const char CRfv[] = "rezai.txt";

int main()
{
    int Suvalge(int suvalge[], int liko[]);
     int suvalge[cmax];
     int liko[10];


    Suvalge(suvalge,liko);

    ofstream fr(CRfv);
    for (int d = 0; d < 20; d++)
    fr << suvalge[d] << " ";
    fr.close();


    return 0;
}

int Suvalge(int suvalge[], int liko[])
{
     for (int h = 0; h < 20; h++)
        suvalge[h] = 0;           // nunulinam, kad galetume daryti suma.

    ifstream fd (CDfv);
      for (int i = 0; i < 10; i++)
    { fd >> suvalge[i]; liko[i] = 10 - suvalge[i];}
    fd.close();

    for (int i = 0; i < 10; i++)
    {

        int  j = i+1;
        while (liko[i] > 0)  // Sukam cikla kol nebera vysniu ir einam toliau.
           {

            suvalge[j]++;
            liko[i]--;
            j++;
           }
    }

}
