#include <iostream>
#include "Player.hpp"
#include "Point.hpp"
#include "Grid.hpp"
#include "Game.hpp"
#include "IA.hpp"

void getCoord(Game &game,bool isHuman,const Player &p)
{
    Point t;
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

void checkStatus(Game gm,Grid gr)
{
    if (gr.isFull() && (!gm.checkWinGame()))
    {
        std::cout << "Match nul" << std::endl;
    }
}


int main()
{
    std::string tmp{};
    char temp{};
    Grid gr{};
    std::cout << "Entrer 1 pour le mode 1 joueur et un autre caractère pour le mode 2 joueurs" << std::endl;
    std::cin >> temp;
    std::cin.clear();
    std::cin.ignore(255,'\n');
    if (temp == '1')
    {
        std::cout << "Mode 1 joueur" << std::endl;
        Player p1{1};
        IA p2{gr.getContent(), true};
        Game game{p1,p2,gr};
        Point t;
        while (!gr.isFull() || !game.checkWinGame())
        {
            game.turn(1);
            std::cout << p1.getName() <<" entrez les coordonnées du point pour placer votre symbole :" << std::endl;
            getCoord(game,true,p1);
            gr.printGrid();
            std::cout << "--------------------------" << std::endl;
            if (game.checkWinGame() || gr.isFull()) break;
            game.turn(2);
            getCoord(game,false,p2);
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
        }
        checkStatus(game,gr);
    }
    else
    {
        Player p1{1};
        Player p2{2};
        Game game{p1,p2,gr};
        Point t;
        while (!gr.isFull() || !game.checkWinGame())
        {
            game.turn(1);
            getCoord(game,true,p1);
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
            game.turn(2);
            std::cout << p2.getName() <<" entrez les coordonnées du point pour placer votre symbole :" << std::endl;
            getCoord(game,true,p2);
            std::cout << "--------------------------" << std::endl;
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
        }
        checkStatus(game,gr);
    }
    return 0;
}