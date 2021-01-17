#include "Point.hpp"
#include <iostream>

std::ostream & operator << (std::ostream &os,const Point &pt)
{
    os << "(" << pt.x << "," << pt.y << ")";
    return os;
}