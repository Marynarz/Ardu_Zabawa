#include <iostream>
#include "Plansza.hpp"

using namespace std;

int main()
{
    Plansza p1(5,5);
    p1.showPlansza();
    p1.setPoint(0,1);
    cout <<endl<<endl;
    p1.showPlansza();
    return 0;
}
