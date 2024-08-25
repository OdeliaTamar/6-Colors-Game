#include"LocalComputer.h"
#include"Controller.h"
const sf::Color& LocalComputer::chooseColor(Controller& controller, bool colorHaveChoosed)
{
    sf::Color computerColor = Algorithm::getInstance().LocalChoose(controller, colorHaveChoosed);
    controller.setComputerColor(computerColor);
    m_chooseColor = computerColor;
    return computerColor;
}