#pragma once
#include <vector>
#include <memory>
#include "Hexagon.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>
class Cell
{
public:
	Cell(sf::Vector2f pos, sf::Color c):m_hexagon(pos, c){}
	~Cell() = default;
	void draw(sf::RenderWindow& window);
	sf::Vector2f getOrigin()const { return m_hexagon.getOrigin(); }
	sf::Vector2f getPosition()const { return m_hexagon.getPosition(); }
	void setNeighbor(std::shared_ptr<Cell> neighbor) { m_neighbors.emplace_back(neighbor); }
	const std::vector<std::shared_ptr<Cell>>& getNeighbors() { return m_neighbors; }
	sf::Color getColor() const { return m_hexagon.getColor(); }
	void setColor(const sf::Color& c);
	void setNeighborColor(const sf::Color& c);
	bool getVisit()const { return m_visit; }
	void setVisit(bool visit) { m_visit=visit; }

private:
	Hexagon m_hexagon;
	std::vector<std::shared_ptr<Cell>> m_neighbors;
	bool m_visit=false;
};

