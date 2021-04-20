#include "Game.hpp"
#include <iostream>

Game::Game(Player &player1, Player &player2, Grid &gameGrid) noexcept
    :m_p1(player1),m_p2(player2),m_gr(gameGrid)
{
    std::cout << "Start of the game\n";
}

Game::~Game()
{
    std::cout << "End of the game\n";
}

// Method to check if someone won the game
// @return bool
bool Game::checkWinGame() const noexcept
{
    auto const tmp = m_gr.checkWin();
    bool p1 = (tmp == m_p1.getSymbol());
    bool p2 = (tmp == m_p2.getSymbol());
    if(p1)
    {
        std::cout << m_p1.getName() << " won\n";
        return p1;
    }
    if(p2)
    {
        std::cout << m_p2.getName() << " won\n";
        return p2;
    }
    return false;
}

// Method to reset the game
void Game::resetGame() noexcept
{
    m_gr.resetGrid();
}

// Method to give the hand to a player
// @param unsigned short int
void Game::turn(unsigned short p) noexcept
{
    switch (p)
    {
        case 1 :
            m_p1.myTurn();
            m_p2.passTurn();
            return;
        case 2 :
            m_p1.passTurn();
            m_p2.myTurn();
            return;
        default:
            return;
    }
}

// Method to insert an element in the grid of the game
// @param Player
// @param Point
// @return bool
bool Game::insert(const Player &p, const Point &pos) noexcept
{
    if(!m_gr.isFreeGrid(pos)) return false;
    m_gr.insertInGrid(pos,p.getSymbol());
    return true;
}

// Return  the game grid
Grid  Game::getGrid() const
{
    return m_gr;
}