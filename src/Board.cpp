#include "Utilities.h"
#include "Board.h"

Board::Board()
{
	m_colors.emplace_back(sf::Color::Red);
	m_colors.emplace_back(sf::Color::Yellow);
	m_colors.emplace_back(sf::Color::Green);
	m_colors.emplace_back(sf::Color::Cyan);////
	m_colors.emplace_back(sf::Color(255, 51, 153));
	m_colors.emplace_back(sf::Color(255, 128, 0));
	createBoard();
}
//-----------------------------------------------------
//create the board
void Board::createBoard()
{
	int num, r_index = R_INDEX, c_index = C_INDEX;
	float factor = float(sqrt(3.f) / 2) * HEX_SIZE;
	int rowFactor = 0;
	float colFactor = COL_FACTOR;
	for (int col = 0; col < MAX_COL; col++)
	{
		for (int row = 0; row < MAX_ROW; row++)
		{
			num = rand() % NUM_OF_COLORS;
			r_index = (row * factor);
			m_board.emplace_back(std::make_shared<Cell>(sf::Vector2f{ float(COL_FACTOR + (row*factor*2 + 1) + rowFactor),
								float(colFactor + (col*factor*2 * 0.75)) }, m_colors[num]));
		}
		handleRows(rowFactor);
		colFactor += 5;
	}
}
//-----------------------------------------------------
//draw the board
void Board::draw(sf::RenderWindow& window)
{
	defiedNeighbore();

	for (auto& cell : m_board)
	{
		cell->draw(window);
	}
}
//-----------------------------------------------------
//defied the nighboors
void Board::defiedNeighbore()
{
	for (size_t i = 0; i < m_board.size(); i++)
	{
		sf::Vector2f center1 = m_board[i]->getPosition();
		for (size_t j = 0; j < m_board.size(); j++)
		{
			sf::Vector2f center2 = m_board[j]->getPosition();
			float distance = std::sqrt(std::pow(center2.x - center1.x, 2) + std::pow(center2.y - center1.y, 2));
			float sumRadii = HEX_SIZE * 2;
			if (distance <= sumRadii)
			{
				m_board[i]->setNeighbor(m_board[j]);
			}
		}
	}
}
//------------------------------------
//handle rows factor
void Board::handleRows(int& rowFactor)
{
	if (rowFactor == 17)
		rowFactor = 0;
	else if (rowFactor == 0)
		rowFactor = 17;
}
