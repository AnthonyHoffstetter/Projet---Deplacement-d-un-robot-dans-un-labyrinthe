#include <iostream>
#include "position.h"

using namespace std;

//Transformer cette fonction en test unitaire ! #Anthony
void testPosition()
{
    position p1(2,5);
    position p2(3,7);
    position p3(2,5);
    cout<<"p1.x = "<<p1.getX()<<" et p1.y = "<<p1.getY()<<endl;
    if(p1==p2)
        cout<<"p1 et p2 sont egaux"<<endl;
    if(p1==p3)
        cout<<"p1 et p3 sont egaux"<<endl;
    if(p1!=p2)
        cout<<"p1 et p2 sont differents"<<endl;
}

int main()
{
    //testPosition();
}
