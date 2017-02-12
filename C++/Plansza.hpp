#ifndef Plansza_hpp
#define Plansza_hpp

#include <iostream>

using namespace std;

class Plansza
{
    unsigned const int x;
    unsigned const int y;
    int **plansza;
    
public:
    Plansza(unsigned const int x =3, unsigned const int y =3);
    ~Plansza();
    void showPlansza();
    void setPoint(unsigned const int x1, unsigned const int y1);
};

#endif
