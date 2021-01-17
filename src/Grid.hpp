#ifndef TICTACTOE_GRID_H
#define TICTACTOE_GRID_H

#include <array>
#include "Point.hpp"

/** Au fait les x sont dans le sens vertical du haut vers le bas et les y dans le sens horizontal de la gauche
 * vers la droite (c'est comme ça que les 2d arrays sont et j'allais pas inverser le tout)
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