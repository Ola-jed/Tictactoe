#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include "Player.hpp"
#include "Grid.hpp"

class Game
{
    private:
        Player& m_p1;
        Player& m_p2;
        Grid& m_gr;
    public:
        Game(Player &player1,Player &player2,Grid &gameGrid) noexcept;
        ~Game();
        bool checkWinGame() noexcept;
        void resetGame() noexcept;
        bool insert(const Player &p,const Point &pos) noexcept;
        void turn(unsigned short int p) noexcept;
        Grid getGrid() const;
};

#endif //TICTACTOE_GAME_H