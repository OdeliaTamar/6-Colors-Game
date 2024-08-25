#pragma once
#include"BaseComputer.h"
#include "Algorithm.h"
class controller;
class GlobalComputer :public BaseComputer
{
public:
	GlobalComputer()=default;
	virtual ~GlobalComputer() = default;
	virtual const sf::Color& chooseColor(Controller& controller, bool)override;
private:

};
