#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
class Controller;
class Menu
{
public:
	Menu();
	~Menu()=default;
	void draw(sf::RenderWindow& window);
	const sf::Color& chooseColor(Controller& controller);
	void newGameButtomGraphics(float& x, float& y);
	void newGameButtom(Controller& controller);
	void setTextWinOrLose(bool win);
	const sf::Text& getTextWinOrLose() const { return m_textWinOrLose; }
	void disableColors(sf::Color computerColor,sf::Color playerColor);
	void restartColors();
private:
	std::vector< sf::RectangleShape> m_rectangle;
	std::vector< sf::Color> m_colors;
	sf::RectangleShape m_newGame;
	sf::Font m_font;
	sf::Text m_textNewGame;
	sf::Text m_textWinOrLose;
	
};
