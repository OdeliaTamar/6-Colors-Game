#pragma once
#include <SFML/Graphics.hpp>

class Hexagon
{
public:
	Hexagon(sf::Vector2f pos, sf::Color c);
	~Hexagon() = default;
	sf::Color  getColor()const { return sf::Color(m_hexagon.getFillColor()); }
	void setColor(const sf::Color& color);
	void draw(sf::RenderWindow& window) { window.draw(m_hexagon); }
	sf::Vector2f getOrigin()const { return m_hexagon.getOrigin(); }
	sf::Vector2f getPosition()const { return m_hexagon.getPosition(); }

private:
	sf::CircleShape m_hexagon;
	sf::Color m_color;
};

