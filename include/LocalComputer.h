#pragma once
#include"BaseComputer.h"
#include"Algorithm.h"
class Controller;
class LocalComputer :public BaseComputer
{
public:
    LocalComputer() = default;
    virtual ~LocalComputer() = default;
    virtual const sf::Color& chooseColor(Controller& controller, bool)override;
private:

};