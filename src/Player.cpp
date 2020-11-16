//
// Created by ola on 02/11/2020.
#include "Player.hpp"
#include <iostream>
Player::Player(const std::string &name, char symbol) noexcept
    :m_name(name),m_symbol(symbol)
{
    std::cout << name << " a rejoint la partie  " << std::endl;
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
Player::~Player()
{}