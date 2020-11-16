// Created by ola on 02/11/2020.
// Class for the players and the services provided to/by the player object
#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H
#include <string>
class Player
{
    protected:
        std::string m_name;
        char m_symbol;
        bool m_turn{false};
    public:
        Player(const std::string &name,char symbol) noexcept;
        std::string getName() const noexcept;
        char getSymbol() const noexcept;
        bool getTurn() const noexcept;
        void myTurn() noexcept;
        void passTurn() noexcept;
        ~Player();
};

#endif //TICTACTOE_PLAYER_H