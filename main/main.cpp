#include <iostream>
#include "gamemanager.hpp"

int main()
{
    std::string tmp{};
    char temp{};
    Grid gr{};
    std::cout << "Enter 1 for the 1P mode and an other char for 2P mode" << std::endl;
    std::cin >> temp;
    std::cin.clear();
    std::cin.ignore(255,'\n');
    if (temp == '1')
    {
        std::cout << "1P mode" << std::endl;
        Player p1{1};
        IA p2{gr.getContent(), true};
        Game game{p1,p2,gr};
        Point t{};
        while (!gr.isFull() || !game.checkWinGame())
        {
            game.turn(1);
            std::cout << p1.getName() <<" Enter coordinates :" << std::endl;
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
        Point t{};
        while (!gr.isFull() || !game.checkWinGame())
        {
            game.turn(1);
            getCoord(game,true,p1);
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
            game.turn(2);
            std::cout << p2.getName() <<" Enter coordinates :" << std::endl;
            getCoord(game,true,p2);
            std::cout << "--------------------------" << std::endl;
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
        }
        checkStatus(game,gr);
    }
    return 0;
}