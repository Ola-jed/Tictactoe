// Created by ola on 03/11/2020.
// Class IA for one player mode
#ifndef TICTACTOE_IA_H
#define TICTACTOE_IA_H
#include "Player.hpp"
#include "Grid.hpp"
#include "Point.hpp"
#include <array>
class IA: public Player
{
    protected:
    IA(const std::array<std::array<char, 3>, 3> &gr);

    std::array<std::array<char,3>,3> m_thegrid;
        bool m_level;
    public:
        IA(const std::array<std::array<char,3>,3> &gr,bool hardLevel) noexcept;
        ~IA();
        Point play() noexcept;
        void updateTheGrid(const Grid &ngrid) noexcept;
        bool isForeign(char t) const noexcept;
};
#endif //TICTACTOE_IA_H