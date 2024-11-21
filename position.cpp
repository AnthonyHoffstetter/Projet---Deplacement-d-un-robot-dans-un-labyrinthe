#include "position.h"

position::position(int x,int y) :
    d_x{x}, d_y{y}
{}


int position::getX() const
{
    return d_x;
}

int position::getY() const
{
    return d_y;
}

void position::setPosition(int x,int y)
{
    d_x=x;
    d_y=y;
}

bool position::estEgale(const position &p) const
{
    return d_x==p.getX() && d_y==p.getY();
}

bool position::operator==(const position &p) const
{
    return estEgale(p);
}

bool position::operator!=(const position &p) const
{
    return !estEgale(p);
}

