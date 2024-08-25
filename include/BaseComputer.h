#pragma once
#include <SFML/Graphics.hpp>
class Controller;
class BaseComputer
{
public:
    BaseComputer() = default;
    virtual ~BaseComputer() = default;
    virtual const sf::Color& chooseColor(Controller& controller, bool) = 0;
    sf::Color getColorMember() { return m_chooseColor; }

protected:
    sf::Color m_chooseColor;
};