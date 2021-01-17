#include "Player.hpp"
#include <iostream>

Player::Player(int playerId) noexcept
{
    std::cout << " Joueur " << playerId << ": \nEntrer votre nom : " << std::endl;
    std::cin >> m_name;
    std::cout << "Choisir votre symbole : " << std::endl;
    std::cin >> m_symbol;
    std::cout << m_name << " a rejoint la partie  " << std::endl;
}

Player::Player(const std::string &name, char symbol) noexcept
    :m_name(name),m_symbol(symbol)
{
    std::cout << name << " a rejoint la partie  " << std::endl;
}

Player::Player(const Player &player)
    :m_name(player.m_name),m_symbol(player.m_symbol)
{
    std::cout << player.m_name << " a rejoint la partie  " << std::endl;
}

std::string Player::getName() const noexcept
{
    return m_name;
}

char Player::getSymbol() const noexcept
{
    return m_symbol;
}

bool Player::getTurn() const noexcept
{
    return m_turn;
}

void Player::myTurn() noexcept
{
    m_turn = true;
}

void Player::passTurn() noexcept
{
    m_turn = false;
}