#include "Menu.h"
#include "Menu.h"
#include "Menu.h"
#include "Menu.h"
#include "Utilities.h"
#include "Controller.h"

Menu::Menu()
{
	float x= COL, y = ROW;
	for (int i = 0; i < NUM_OF_COLORS; i++)
	{
		m_rectangle.emplace_back(sf::RectangleShape());
		m_rectangle[i].setSize(sf::Vector2f(REC_SIZE, REC_SIZE));
		m_rectangle[i].setPosition(x, y);
		m_rectangle[i].setOutlineColor(sf::Color::Black);///////////////
		m_rectangle[i].setOutlineThickness(4.f);
		x += 50.f;
	}
	restartColors();//restart the rectangles colors
	
	m_colors.emplace_back(sf::Color(sf::Color::Red));
	m_colors.emplace_back(sf::Color(sf::Color::Yellow));
	m_colors.emplace_back(sf::Color(sf::Color::Green));
	m_colors.emplace_back(sf::Color(sf::Color::Cyan));
	m_colors.emplace_back(sf::Color(sf::Color(255, 51, 153)));
	m_colors.emplace_back(sf::Color(sf::Color(255, 128, 0)));

	newGameButtomGraphics(x, y);
}
//---------------------------------------------------
//new game buttom graphics
void Menu::newGameButtomGraphics(float& x, float& y)
{
	m_newGame.setFillColor(sf::Color::White);
	m_newGame.setSize(sf::Vector2f(NEW_GAME_LENGTH, NEW_GAME_WIDTH));
	m_newGame.setPosition(x, y);
	m_font.loadFromFile("C:/Windows/Fonts/calibrib.ttf");
	m_textNewGame.setFont(m_font);
	if (!m_font.loadFromFile("C:/Windows/Fonts/calibrib.ttf"))
	{
		std::cout << "error: cannot load the font";
		return;
	}
	m_textNewGame.setString("New Game");
	m_textNewGame.setCharacterSize(NEW_GAME_TEXT_SIZE); // in pixels, not points
	m_textNewGame.setFillColor(sf::Color::Black);// set the color
	m_textNewGame.setStyle(sf::Text::Bold);// set the text style
	m_textNewGame.setPosition(x, y);// the position of the text

	m_textWinOrLose.setFont(m_font);
	m_textWinOrLose.setString("WinLose");
	m_textWinOrLose.setCharacterSize(WIN_TEXT_SIZE); // in pixels, not points
	m_textWinOrLose.setFillColor(sf::Color::Cyan);// set the color
	m_textWinOrLose.setStyle(sf::Text::Bold);// set the text style
	m_textWinOrLose.setPosition(WIN_TEXT_POSE_LENGTH, WIN_TEXT_POSE_WIDTH);// the position of the text
}
//-----------------------------------------------------
//draw the menu
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_rectangle.size(); i++)
	{
		window.draw(m_rectangle[i]);
	}
	window.draw(m_newGame);
	window.draw(m_textNewGame);
}
//-------------------------------------------------------------
//new game buttom
void Menu::newGameButtom(Controller& controller)
{
	restartColors();
	controller.restartNewGame();
}
//-----------------------------------------------
//set text Win or Lose
void Menu::setTextWinOrLose(bool win)
{
	if (win)
		m_textWinOrLose.setString("You Win :)");
	else
		m_textWinOrLose.setString("You Lose :(");
}
//------------------------------------------------
//disable colors
void Menu::disableColors(sf::Color computerColor, sf::Color playerColor)
{
	restartColors();

	for (int i = 0; i < NUM_OF_COLORS; i++)
	{
		if (m_rectangle[i].getFillColor() == computerColor || m_rectangle[i].getFillColor() == playerColor)
			m_rectangle[i].setFillColor(sf::Color(140, 140, 140));////
	}
}
//----------------------------------------------
//restart the rectangles colors
void Menu::restartColors()
{
	m_rectangle[0].setFillColor(sf::Color::Red);
	m_rectangle[1].setFillColor(sf::Color::Yellow);
	m_rectangle[2].setFillColor(sf::Color::Green);
	m_rectangle[3].setFillColor(sf::Color::Cyan);
	m_rectangle[4].setFillColor(sf::Color(255, 51, 153));
	m_rectangle[5].setFillColor(sf::Color(255, 128, 0));
}
//-----------------------------------------------
//choose the color
const sf::Color& Menu::chooseColor(Controller& controller)
{

	sf::Color colorChoose;
	
	while (controller.getWindow().isOpen())
	{
		for (auto event = sf::Event{}; controller.getWindow().pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				controller.getWindow().close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				if (m_newGame.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					// Perform the desired action when the "New Game" button is clicked
					newGameButtom(controller);
				}
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (int i = 0; i < m_rectangle.size(); i++)
					{
						if (m_rectangle[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
						{
							colorChoose = m_colors[i];
					
							return colorChoose;
						}
					}
				}


			}break;
			}
		}

	}
}
