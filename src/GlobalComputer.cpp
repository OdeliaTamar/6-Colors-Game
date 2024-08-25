
#include"GlobalComputer.h"
#include"Controller.h"

const sf::Color& GlobalComputer::chooseColor(Controller& controller, bool colorHaveChoosed)
{
    sf::Color computerColor = Algorithm::getInstance().GlobalChoose(controller, colorHaveChoosed);
    controller.setComputerColor(computerColor);
    m_chooseColor = computerColor;
    return computerColor;

}