// Created by ola on 02/11/2020.
#include "Grid.hpp"
#include <iostream>
Grid::Grid() noexcept
{
    std::cout << "Construction de la grille en cours .........." << std::endl;
    resetGrid();
}
Grid::Grid(const Grid &toCopy)
    :m_self(toCopy.m_self)
{}
Grid::~Grid()
{}
// Method to check if the cell is free
// @param Point
// @return bool
bool Grid::isFreeGrid(const Point &p) const noexcept
{
    return (m_self[p.x][p.y] == ' ');
}
// Method to insert a char into the grid
// @param Point
// @param char
// @return bool
// Returns true if it is good and false if the cell is not empty
bool Grid::insertInGrid(const Point &p,char toAdd) noexcept
{
    if (!isFreeGrid(p)) return false;
    m_self[p.x][p.y] = toAdd;
    return true;
}
// Method to check if a char have won
// @return char
char Grid::checkWin() const noexcept
{
    // [0][0]
    bool firstType  = (m_self[0][0] == m_self[0][1]) && (m_self[0][1] == m_self[0][2]);
    bool secondType = (m_self[0][0] == m_self[1][0]) && (m_self[1][0] == m_self[2][0]);
    bool thirdType  = (m_self[0][0] == m_self[1][1]) && (m_self[1][1] == m_self[2][2]);
    // [1][2]
    bool fourthType = (m_self[0][2] == m_self[1][2]) && (m_self[1][2] == m_self[2][2]);
    bool fifthType  = (m_self[1][0] == m_self[1][1]) && (m_self[1][1] == m_self[1][2]);
    // [2][0]
    bool sixthType   = (m_self[2][0] == m_self[2][1]) && (m_self[2][1] == m_self[2][2]);
    bool seventhType = (m_self[2][0] == m_self[1][1]) && (m_self[1][1] == m_self[0][2]);
    // [0][1]
    bool eightthType = (m_self[0][1] == m_self[1][1]) && (m_self[1][1] == m_self[2][1]);
    if (firstType || secondType || thirdType)
    {
        return m_self[0][0];
    }
    if (fourthType || fifthType)
    {
        return m_self[1][2];
    }
    if (sixthType || seventhType)
    {
        return m_self[2][0];
    }
    if (eightthType)
    {
        return m_self[0][1];
    }
    return ' ';
}
// Method to print the grid by going throught the array
void Grid::printGrid() noexcept
{
    for (std::size_t i = 0;i < m_self.size();++i)
    {
        for (std::size_t j= 0; j < m_self.size(); j++)
        {
            std::cout << " | " << m_self[i][j] << " | ";
        }
        std::cout << "\n";
    }
}
// Method to reset the state of the grid
void Grid::resetGrid() noexcept
{
    for (std::size_t i = 0;i < m_self.size();++i)
    {
        for (std::size_t j= 0; j < m_self.size(); j++)
        {
            m_self[i][j] = ' ';
        }
    }
}
// Method to check if the grid is Full, the game will be draw
bool Grid::isFull() const noexcept
{
    for (std::size_t i = 0;i < m_self.size();++i)
    {
        for (std::size_t j= 0; j < m_self.size(); j++)
        {
            if(m_self[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
std::array<std::array<char, 3>, 3> Grid::getContent() const
{
    return m_self;
}
