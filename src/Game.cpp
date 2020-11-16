// Created by ola on 02/11/2020.
#include "Game.hpp"
#include <iostream>

Game::Game(Player &p1, Player &p2, Grid &gr) noexcept
    :m_p1(p1),m_p2(p2),m_gr(gr)
{
    std::cout << "Début de la partie" << std::endl;
}
Game::~Game()
{
    m_gr.resetGrid();
    std::cout << "Fin de la partie" << std::endl;
}
// Method to check if someone won the game
// @return bool
bool Game::checkWinGame() noexcept
{
    auto const tmp = m_gr.checkWin();
    bool p1 = (tmp == m_p1.getSymbol());
    bool p2 = (tmp == m_p2.getSymbol());
    if(p1)
    {
        std::cout << m_p1.getName() << " a gagné la partie" << std::endl;
        return p1;
    }
    if(p2)
    {
        std::cout << m_p2.getName() << " a gagné la partie" << std::endl;
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