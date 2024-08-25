#include "Display.h"
#include"Display.h"
#include "Controller.h"
#include "Utilities.h"
Display::Display()
{
	float x = DISPLAY_X, y = DISPLAY_Y;
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		m_rectangle.emplace_back(sf::RectangleShape());
		m_rectangle[i].setSize(sf::Vector2f(350, 50));
		m_rectangle[i].setFillColor(sf::Color::White);
		m_rectangle[i].setPosition(x, y);
		
		y += 80.f;
	}
	m_texts.resize(m_rectangle.size());
	m_font.loadFromFile("C:/Windows/Fonts/calibrib.ttf");

	displayGraphics();
}
//-------------------------------------------------
//handle the graphics of the display
void Display::displayGraphics()
{
	float x = DISPLAY_GR_X, y = DISPLAY_GR_Y;
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		m_texts[i].setFont(m_font);
		if (!m_font.loadFromFile("C:/Windows/Fonts/calibrib.ttf"))
		{
			std::cout << "error: cannot load the font";
			return;
		}
		
		m_texts[i].setCharacterSize(TEXTS_SIZE); // in pixels, not points
		m_texts[i].setFillColor(sf::Color::Black);// set the color
		m_texts[i].setStyle(sf::Text::Bold);// set the text style
		m_texts[i].setPosition(x, y);// the position of the text
		y += 80.f;
	}

	m_texts[0].setString("Random Player");
	m_texts[1].setString("Local - Not Smart Player");
	m_texts[2].setString("Global - Smart Player");
}
//-------------------------------------------------
void Display::draw(sf::RenderWindow& window)
{
	window.clear();
	for (int i = 0; i < m_rectangle.size(); i++)
	{
		window.draw(m_rectangle[i]);
		window.draw(m_texts[i]);
	}
	window.display();
	
}
//-------------------------------------------------------------
// handle the click of the buttons and return the texture of the button
void Display::click(Controller& controller)
{
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
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (int i = 0; i < m_rectangle.size(); i++)
					{
						if (m_rectangle[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
						{
							controller.restartComputer(i);
							return;
						}
					}
				}

			}break;
			}
		}
	}
}

