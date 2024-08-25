#include "Cell.h"

//draw the cell
void Cell::draw(sf::RenderWindow& window)
{
	m_hexagon.draw(window);
}
//------------------------------------------------
//set the cell color
void Cell::setColor(const sf::Color& c)
{
	m_hexagon.setColor(c);
}
//------------------------------------------------
//set the neigbors color
void Cell::setNeighborColor(const sf::Color& c)
{
	for (auto& i : m_neighbors)
	{
		i->setColor(c);
	}
}
