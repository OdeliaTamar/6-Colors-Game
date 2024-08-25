#include "Hexagon.h"
#include "Utilities.h"
Hexagon::Hexagon(sf::Vector2f pos, sf::Color c) : m_hexagon(HEX_SIZE, NUM_OF_VERTICES)
{
	 m_hexagon.setPosition(pos);
	 m_hexagon.setFillColor(c); 
	 m_hexagon.setOrigin(m_hexagon.getRadius(), m_hexagon.getRadius());
	 m_hexagon.setOutlineColor(sf::Color::Black);
	 m_hexagon.setOutlineThickness(2.f);
}

void Hexagon::setColor(const sf::Color& color)
{
	m_hexagon.setFillColor(color);
	m_color = color;
}
