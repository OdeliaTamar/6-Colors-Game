#include "RegularComputer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Controller.h"
#include "Utilities.h"
//choose color
const sf::Color& RegularComputer::chooseColor(Controller& controller, bool colorHaveChoosed)
{
    sf::Color computerColor;
    sf::Color playerColor = controller.getPlayerColor();
    if (!colorHaveChoosed)//first time
    {
        do
        {
            computerColor = randNumber();
        } while (computerColor == playerColor);
        controller.setComputerColor(computerColor);
        m_chooseColor = computerColor;
        return computerColor;
    }
    else//other time
    {
        do
        {
            computerColor = randNumber();
        } while (computerColor == playerColor || computerColor == m_chooseColor);
        controller.setComputerColor(computerColor);
        m_chooseColor = computerColor;
        return computerColor;
    }
}
//---------------------------------------------
//rand number for color
sf::Color RegularComputer::randNumber()
{
    int randomNumber = std::rand() % NUM_OF_COLORS;
    switch (randomNumber) 
    {
    case 0:
        return sf::Color::Red;
    case 1:
        return sf::Color::Yellow;
    case 2:
        return sf::Color::Green;
    case 3:
        return sf::Color::Cyan;
    case 4:
        return sf::Color(255, 51, 153);
    case 5:
        return sf::Color(255, 128, 0);
    }
}