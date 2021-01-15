// Created by ola on 02/11/2020.
#ifndef TICTACTOE_POINT_H
#define TICTACTOE_POINT_H
#include <iostream>
struct Point
{
    int x;int y;
};
std::ostream & operator << (std::ostream &os,const Point &pt);
#endif //TICTACTOE_POINT_H