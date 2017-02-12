#include "Plansza.hpp"
Plansza::Plansza(unsigned const int x, unsigned const int y):y(y),x(x)
{
    plansza = new int *[y];
    for(int i =0; i<y; i++)
        plansza[i] = new int [x];
}
Plansza::~Plansza()
{
    delete [] plansza;
}
void Plansza::showPlansza()
{
    for(int i=0; i<x;i++)
    {
        for(int j=0;j<y;j++)
            cout <<plansza[i][j];
        cout <<endl;
    }
}
