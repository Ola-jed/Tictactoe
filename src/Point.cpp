// Created by ola on 02/11/2020.
// Function for the << operator overloading to print a point
// @param ostream
// @param Point
#include "Point.hpp"
#include <iostream>
std::ostream & operator << (std::ostream &os,const Point &pt)
{
    os << "(" << pt.x << "," << pt.y << ")";
    return os;
}