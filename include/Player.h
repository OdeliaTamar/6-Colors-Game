#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
class Controller;
class Player
{
public:
    Player() = default;
    ~Player() = default;
    const sf::Color& chooseColor(Controller& controller, bool); 
    sf::Color getColorMember() { return m_chooseColor; }

private:
    sf::Color m_chooseColor;
};