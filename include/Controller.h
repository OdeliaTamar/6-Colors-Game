#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Menu.h"
#include"Player.h"
#include"BaseComputer.h"
#include"Display.h"
#include "RegularComputer.h"
#include"LocalComputer.h"
#include"GlobalComputer.h"

class Controller
{
public:
	Controller();
	~Controller()=default;
	void run();
	void restartComputer(int kind);
	Menu getMenu()&   { return m_menu; }
	sf::RenderWindow& getWindow() { return m_window; }
	std::vector < std::shared_ptr<Cell>>& getComputerVec() { return m_computerVec; }
	void setPlayerColor(sf::Color c) { m_playerColor = c; }
	void setComputerColor(sf::Color c) { m_computerColor = c; }
	sf::Color getPlayerColor() { return m_playerColor; }
	sf::Color getComputerColor() { return m_computerColor; }
	void restartNewGame();
	
private:
	bool Win();
	void displayText(); 
	void restart();
	
	sf::RenderWindow m_window;
	Board m_board;
	Menu m_menu;
	std::unique_ptr <Player> m_player;
	std::unique_ptr<BaseComputer> m_computer;
	std::vector<std::shared_ptr<Cell>> m_userVec;
	std::vector<std::shared_ptr<Cell>> m_computerVec;
	Display m_display;
	sf::Color m_color;
	sf::Color m_playerColor;
	sf::Color m_computerColor;
	bool colorHaveChoosed = false;
};
