#include"Player.h"
#include "Controller.h"

//choose color
const sf::Color& Player::chooseColor(Controller& controller, bool colorHaveChoosed)
{
    sf::Color playerColor;
    if (!colorHaveChoosed)//First choice of color in the game
    {
        playerColor = controller.getMenu().chooseColor(controller);//הצבע שהשחקן בחר
        controller.setPlayerColor(playerColor);
        m_chooseColor = playerColor;
        return  playerColor;
    }
    else//a choice that is not the first and you need to make sure that an forbidden color is not taken
    {
        sf::Color computerColor;
        computerColor = controller.getComputerColor();
        do
        {
            playerColor = controller.getMenu().chooseColor(controller);
        } while (playerColor == m_chooseColor || playerColor == computerColor);

    }
    controller.setPlayerColor(playerColor);
    m_chooseColor = playerColor;

    return  playerColor;
}