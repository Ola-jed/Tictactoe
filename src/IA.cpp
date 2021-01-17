#include "IA.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

IA::IA(const std::array<std::array<char, 3>, 3> &gridToCopy,bool hardLevel) noexcept
    :Player("IA",'W'),m_thegrid(gridToCopy),m_level(hardLevel)
{}

 IA::IA(const Player &playerBase) noexcept
    :Player(playerBase),m_level(false),m_thegrid({})
{}

IA::~IA()
{}

// Method to make the ia play
// @return Point
Point IA::play() noexcept
{
    int first{0},second{0};
    if(m_level)
    {
        // Ici on va analyser la grille et voir les endroits dangereux
        constexpr int limit  = 3;
        for (std::size_t i = 0;i < m_thegrid.size();++i)
        {
            for (std::size_t j= 0; j < m_thegrid.size(); j++)
            {
                try
                {
                    if(m_thegrid.at(i).at(j) == m_thegrid.at(i+1).at(j+1)) // Alignement oblique
                    {
                        first  = ((i+2) < limit) ? i+2 : i-1;
                        second = ((j+2) < limit) ? j+2 : j-1;
                        return Point({first,second});
                    }
                    else
                    {
                        std::srand(std::time(nullptr));
                        first  = std::rand()%3;
                        second = std::rand()%3;
                        return Point({first,second});
                    }
                }
                catch (const std::exception &e)
                {
                    // Exception levée à cause du tableau, jeu random
                    std::srand(std::time(nullptr));
                    first  = std::rand()%3;
                    second = std::rand()%3;
                    return Point({first,second});
                }
            }
        }
    }
    else
    {
        // Ici l'ia sera bete
        std::srand(std::time(nullptr));
        first  = std::rand()%3;
        second = std::rand()%3;
        return Point({first,second});
    }
    return Point({0,0});
}

// Method to update the copy of the grid owned by the ia
// @return void
// @param grid
void IA::updateTheGrid(const Grid &ngrid) noexcept
{
    m_thegrid = ngrid.getContent();
}

// Method to check is the char is for the IA or not
// @return bool
// @param char
bool IA::isForeign(char t) const noexcept
{
    return t!='W';
}