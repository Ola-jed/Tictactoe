#include "Player.hpp"
#include <iostream>

Player::Player(int playerId) noexcept
{
    std::cout << "Player " << playerId << ": \nEnter your name : " << std::endl;
    std::cin >> m_name;
    std::cout << "Choose symbol : " << std::endl;
    std::cin >> m_symbol;
    std::cout << m_name << " join the game  " << std::endl;
}

Player::Player(const std::string &name, char symbol) noexcept
    :m_name(name),m_symbol(symbol)
{
    std::cout << name << " joined the game\n";
}

Player::Player(const Player &player)
    :m_name(player.m_name),m_symbol(player.m_symbol)
{
    std::cout << player.m_name << " joined the game\n";
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