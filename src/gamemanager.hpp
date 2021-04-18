#ifndef TICTACTOE_GAMEMANAGER_HPP
#define TICTACTOE_GAMEMANAGER_HPP
#include "Player.hpp"
#include "Point.hpp"
#include "Grid.hpp"
#include "Game.hpp"
#include "IA.hpp"

inline void getCoord(Game &game,bool isHuman,const Player &p)
{
    Point t{};
    if(isHuman)
    {
        do
        {
            std::cin >> t.x >> t.y;
        } while((t.x < 0) || (t.x > 2) || (t.y < 0) || (t.y > 2) || (!game.insert(p,t)));
    }
    else
    {
        IA ia = static_cast<IA>(p);
        do
        {
            ia.updateTheGrid(game.getGrid());
            t = ia.play();
        } while((t.x < 0) || (t.x > 2) || (t.y < 0) || (t.y > 2) || (!game.insert(ia,t)));
    }
}

void checkStatus(const Game &gm,const Grid& gr)
{
    if (gr.isFull() && (!gm.checkWinGame()))
    {
        std::cout << "Match nul" << std::endl;
    }
}

#endif //TICTACTOE_GAMEMANAGER_HPP
