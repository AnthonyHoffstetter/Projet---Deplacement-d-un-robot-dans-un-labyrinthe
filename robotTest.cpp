#include "doctest.h"
#include "robot.h"

void lesCoordonnesDuRobotSontExactes(const robot& r, int x, int y, char direction)
{
    REQUIRE(r.getPositionActuelle().getX() == x);
    REQUIRE(r.getPositionActuelle().getY() == y);
    REQUIRE(r.getDirection() == direction);
}
