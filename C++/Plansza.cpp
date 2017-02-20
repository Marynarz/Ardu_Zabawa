#include "Plansza.hpp"
Plansza::Plansza(unsigned const int x, unsigned const int y):y(y),x(x)
{
    plansza = new int *[x];
    for(int i =0; i<x; i++)
        plansza[i] = new int [y];
}
Plansza::~Plansza()
{
    delete [] plansza;
}
void Plansza::showPlansza()
{
    for(int i=0; i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(plansza[j][i]!=0)
                cout <<0<<"\t";
            else
                cout <<plansza[j][i]<<"\t";
        }
        cout <<endl;
    }
}
void Plansza::setPoint(unsigned const int x1, unsigned const int y1)
{
    plansza[x1][y1] = 8;
}
