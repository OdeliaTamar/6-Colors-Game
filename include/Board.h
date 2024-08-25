#pragma once
#include <vector>
#include <memory>
#include "Cell.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board();
	~Board() = default;
	void createBoard();
	void draw(sf::RenderWindow& window);
	void defiedNeighbore();
	void handleRows(int& rowFactor);
	std::shared_ptr<Cell>getCell(int index) { return m_board[index]; }
	void deleteBoard() { m_board.clear(); }
private:
	std::vector<std::shared_ptr< Cell>> m_board;
	std::vector<sf::Color> m_colors;

};

