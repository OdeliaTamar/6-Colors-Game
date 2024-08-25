#pragma once
#include <SFML/Graphics.hpp>
#include"Board.h"
class Controller;

class Display
{
public:
	Display();
	~Display()=default;
	void draw(sf::RenderWindow& window);
	void click(Controller& controller);
	
private:
	void displayGraphics();
	std::vector<sf::RectangleShape> m_rectangle;
	sf::Font m_font;
	std::vector<sf::Text> m_texts;
	
};
