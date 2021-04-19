#ifndef TICTACTOE_GRID_H
#define TICTACTOE_GRID_H

#include <array>
#include "Point.hpp"

/**
 * Btw, the x's are in the vertical direction from top to bottom
 * the y's in the horizontal direction from left to the right
 * (that's how the 2d arrays are and I wasn't going to reverse it)
*/

class Grid
{
    private:
        std::array<std::array<char,3>,3> m_self;

    public:
        Grid() noexcept;
        Grid(const Grid &toCopy);
        ~Grid();
        Grid& operator=(const Grid &grid) = default;
        std::array<std::array<char,3>,3> getContent() const;
        bool isFreeGrid(const Point &p) const noexcept;
        bool insertInGrid(const Point &p,char toAdd) noexcept;
        bool isFull() const noexcept;
        char checkWin() const noexcept;
        void printGrid() noexcept;
        void resetGrid() noexcept;
};
#endif //TICTACTOE_GRID_H