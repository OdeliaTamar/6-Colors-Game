#pragma once
#include"BaseComputer.h"
#include <SFML/Graphics.hpp>
class Controller;

class RegularComputer :public BaseComputer
{
public:
    RegularComputer() = default;
    virtual ~RegularComputer() = default;
    virtual const sf::Color& chooseColor(Controller& controller, bool)override;
    sf::Color randNumber();

private:

};