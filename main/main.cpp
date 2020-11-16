#include <iostream>
#include "Player.hpp"
#include "Point.hpp"
#include "Grid.hpp"
#include "Game.hpp"
#include "IA.hpp"

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
        std::cout << " Joueur 1 : \nEntrer votre nom : " << std::endl;
        std::cin >> tmp;
        std::cout << "Choisir votre symbole : " << std::endl;
        std::cin >> temp;
        Player p1{tmp,temp};
        IA p2{gr.getContent(), true};
        Game game{p1,p2,gr};
        Point t;
        while (!gr.isFull() || !game.checkWinGame())
        {
            do
            {
                game.turn(1);
                std::cout << p1.getName() <<" entrez les coordonnées du point pour placer votre symbole :" << std::endl;
                std::cin >> t.x >> t.y;
            } while((t.x < 0) || (t.x > 2) || (t.y < 0) || (t.y > 2) || (!game.insert(p1,t)));
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
            do
            {
                std::cout << "L'ordinateur joue " << std::endl;
                game.turn(2);
                t = p2.play();
            } while((t.x < 0) || (t.x > 2) || (t.y < 0) || (t.y > 2) || (!game.insert(p2,t)));
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
        }
        if (gr.isFull() && (!game.checkWinGame()))
        {
            std::cout << "Match nul" << std::endl;
        }
    }
    else
    {
        std::cout << "Mode 2 joueurs" << std::endl;
        std::cout << " Joueur 1 : \nEntrer votre nom : " << std::endl;
        std::cin >> tmp;
        std::cout << "Choisir votre symbole : " << std::endl;
        std::cin >> temp;
        Player p1{tmp,temp};
        std::cout << " Joueur 2 : \nEntrer votre nom : " << std::endl;
        std::cin >> tmp;
        std::cout << "Choisir votre symbole : " << std::endl;
        std::cin >> temp;
        Player p2{tmp,temp};
        Game game{p1,p2,gr};
        Point t;
        while (!gr.isFull() || !game.checkWinGame())
        {
            do
            {
                game.turn(1);
                std::cout << p1.getName() <<" entrez les coordonnées du point pour placer votre symbole :" << std::endl;
                std::cin >> t.x >> t.y;
            } while((t.x < 0) || (t.x > 2) || (t.y < 0) || (t.y > 2) || (!game.insert(p1,t)));
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
            do
            {
                game.turn(2);
                std::cout << p2.getName() <<" entrez les coordonnées du point pour placer votre symbole :" << std::endl;
                std::cin >> t.x >> t.y;
            } while((t.x < 0) || (t.x > 2) || (t.y < 0) || (t.y > 2) || (!game.insert(p2,t)));
            gr.printGrid();
            if (game.checkWinGame() || gr.isFull()) break;
        }
        if (gr.isFull() && (!game.checkWinGame()))
        {
            std::cout << "Match nul" << std::endl;
        }
    }
    return 0;
}