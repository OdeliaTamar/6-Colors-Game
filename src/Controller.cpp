#include "Controller.h"
#include "Algorithm.h"
#include "Utilities.h"
Controller::Controller() :m_window(sf::VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "6-color"), m_player(std::make_unique <Player>())
{	
}
//-------------------------------------
//run-play the game
void Controller::run()
{
	m_display.draw(m_window);
	m_display.click(*this);
	m_menu.restartColors();
	restart();

	m_window.clear();
	m_board.draw(m_window);
	m_menu.draw(m_window);
	m_window.display();

	while (!Win())
	{
		m_color = m_player->chooseColor(*this, colorHaveChoosed);//the player choose the color
		Algorithm::getInstance().bfs(m_userVec, m_color);

		m_window.clear();
		m_board.draw(m_window);
		m_menu.draw(m_window);
		m_window.display();

		m_color = m_computer->chooseColor(*this, colorHaveChoosed);//the computer choose the color
		colorHaveChoosed = true;
		Algorithm::getInstance().bfs(m_computerVec, m_color);

		m_menu.disableColors(m_computerColor, m_playerColor);
		m_window.clear();
		m_board.draw(m_window);
		m_menu.draw(m_window);
		m_window.display();

	}
}
//---------------------------------------------------
//defiend the players places
void  Controller::restart()
{
	m_userVec.emplace_back(m_board.getCell(USER_CELL));
	m_computerVec.emplace_back(m_board.getCell(COMPUTER_CELL));
}
//-----------------------------------------------
//restart the computer
void Controller::restartComputer(int kind)
{
	switch (kind)
	{
	case 0:
	{
		m_computer = std::make_unique <RegularComputer>();
		break;
	}
	case 1:
	{
		m_computer = std::make_unique <LocalComputer>();
		break;
	}
	case 2:
	{
		m_computer = std::make_unique <GlobalComputer>();
		break;
	}
	}
}
//--------------------------------------------------------
//restart all the things for the new game
void Controller::restartNewGame()
{
	m_computerVec.clear();
	m_userVec.clear();
	colorHaveChoosed = false;
	m_board.deleteBoard();
	m_board.createBoard();
	run();
}
//--------------------------------------------------------
//check the win and lose
bool Controller::Win()
{
	if (m_userVec.size() > size_t(FIFTY_PRECENT))
	{
		m_menu.setTextWinOrLose(true);
		displayText();
		return true;
	}
	else if (m_computerVec.size() > size_t(FIFTY_PRECENT))
	{
		m_menu.setTextWinOrLose(false);
		displayText();
		return true;
	}
	return false;
}
//--------------------------------------------
void Controller::displayText()
{
	m_window.clear();
	m_window.draw(m_menu.getTextWinOrLose());
	m_window.display();
	sf::sleep(sf::seconds(SLEEP_SEC));
}