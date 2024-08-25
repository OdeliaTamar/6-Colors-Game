#include "Algorithm.h"
#include "Controller.h"
#include "Utilities.h"
Algorithm& Algorithm::getInstance()
{
	static Algorithm m_instance;
	return m_instance;
}
//-----------------------------------------------------------------------
Algorithm::Algorithm()
{
}
//--------------------------------------------------------------------------------
//the bfs algorithem
void Algorithm::bfs(std::vector<std::shared_ptr<Cell>>& vec, const sf::Color& color)
{
	//write for all the nighbors writing down that we didn't visit them
	for (auto& cell : vec)
	{
		cell->setVisit(false);
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (!vec[i]->getVisit())
		{
			vec[i]->setVisit(true);
			vec[i]->setColor(color);//counter++ for computer
			int num = vec[i]->getNeighbors().size();

			for (int j = 0; j < vec[i]->getNeighbors().size(); j++)
			{
				sf::Color c = vec[i]->getNeighbors()[j]->getColor();
				if (vec[i]->getNeighbors()[j]->getColor() == color)
				{
					auto it = std::find_if(vec.begin(), vec.end(), [&](const std::shared_ptr<Cell>& ptr)
						{
							// A test that takes into account the value of the pointers
							return ptr == vec[i]->getNeighbors()[j]; 
						});
					//Adding the value only if it is not in the array
					if (it == vec.end())
					{
						vec.emplace_back(vec[i]->getNeighbors()[j]);
					}  
				}
			
			}


		}
	}
	for (int i = 0; i < vec.size(); i++)
		vec[i]->setColor(color);
}
//-----------------------------------------------------------------------------------
//the bfs algorithem of Local computer
const sf::Color& Algorithm::LocalChoose(Controller& controller, bool colorHaveChoosed)
{
	sf::Color computerColor = controller.getComputerColor();
	sf::Color playerColor = controller.getPlayerColor();
	int arr[NUM_OF_COLORS] = { 0 };
	for (auto& cell : controller.getComputerVec())
	{
		cell->setVisit(false);
	}
	for (int index = 0; index < NUM_OF_COLORS; index++)
	{
		sf::Color color = colorToCount(index);
		//write for all the nighbors writing down that we didn't visit them
		for (auto& cell : controller.getComputerVec())
		{
			cell->setVisit(false);
		}
		int lastHexgion = controller.getComputerVec().size();
		if (!controller.getComputerVec()[lastHexgion - 1]->getVisit())
		{
			controller.getComputerVec()[lastHexgion - 1]->setVisit(true);
			for (int j = 0; j < controller.getComputerVec()[lastHexgion - 1]->getNeighbors().size(); j++)// עוברים על הוקטור של השכנים
			{
				if (!colorHaveChoosed)//first time
				{
					if (playerColor == color)
						break;
				}
				else
				{
					if (color == playerColor || color == computerColor)
						break;
				}
				sf::Color c = controller.getComputerVec()[lastHexgion - 1]->getNeighbors()[j]->getColor();//הצבע של השכן
				if (controller.getComputerVec()[lastHexgion - 1]->getNeighbors()[j]->getColor() == color)
				{
					auto it = std::find_if(controller.getComputerVec().begin(), controller.getComputerVec().end(), [&](const std::shared_ptr<Cell>& ptr)
						{
							return ptr == controller.getComputerVec()[lastHexgion - 1]->getNeighbors()[j];
						});
					if (it == controller.getComputerVec().end())
					{
						arr[index]++;
					}
				}
			}
		}
	}
	arr;
	int num = findMaxColor(arr);
	sf::Color c = colorToCount(num);
	return c;
}
//---------------------------------------------------------------------
//the bfs algorithem of Global computer
const sf::Color& Algorithm::GlobalChoose(Controller& controller, bool colorHaveChoosed)
{
	return globalColor(controller, colorHaveChoosed);//מגידרה את המערך של הצבעים שאפשר להשתמש    
}
//-------------------------------------------------------------------
//counter of the colors
void Algorithm::countColor(sf::Color color, int colorCounter[])
{
	if (color == sf::Color::Red)
	{
		colorCounter[0]++;
	}
	else if (color == sf::Color::Yellow)
	{
		colorCounter[1]++;
	}
	else if (color == sf::Color::Green)
	{
		colorCounter[2]++;
	}
	else if (color == sf::Color::Cyan)
	{
		colorCounter[3]++;
	}
	else if (color == sf::Color(255, 51, 153))
	{
		colorCounter[4]++;
	}
	else if (color == sf::Color(255, 128, 0))
	{
		colorCounter[5]++;
	}
}

//------------------------------------------------------------------------------
//choose best color for the global computer
const sf::Color& Algorithm::globalColor(Controller& controller, bool colorHaveChoosed)
{
	sf::Color computerColor = controller.getComputerColor();
	sf::Color playerColor = controller.getPlayerColor();
	int arr[NUM_OF_COLORS] = { 0 };
	for (auto& cell : controller.getComputerVec())
	{
		cell->setVisit(false);
	}
	for (int index = 0; index < NUM_OF_COLORS; index++)
	{
		sf::Color color = colorToCount(index);
		//write for all the nighbors writing down that we didn't visit them
		for (auto& cell : controller.getComputerVec())
		{
			cell->setVisit(false);
		}

		for (int i = 0; i < controller.getComputerVec().size(); i++)
		{
			if (!colorHaveChoosed)//Only the player chose a color
			{
				if (playerColor == color)
					break;
			}
			else//Both players have already chosen a color
			{
				if (color == playerColor || color == computerColor)
					break;
				
			}
			if (!controller.getComputerVec()[i]->getVisit())
			{
				controller.getComputerVec()[i]->setVisit(true);
				controller.getComputerVec()[i]->setColor(color);//counter++ for computer
				int num = controller.getComputerVec()[i]->getNeighbors().size();

				for (int j = 0; j < controller.getComputerVec()[i]->getNeighbors().size(); j++)
				{
					sf::Color c = controller.getComputerVec()[i]->getNeighbors()[j]->getColor();
					if (controller.getComputerVec()[i]->getNeighbors()[j]->getColor() == color)
					{
						auto it = std::find_if(controller.getComputerVec().begin(), controller.getComputerVec().end(), [&](const std::shared_ptr<Cell>& ptr)
							{
								// A test that takes into account the value of the pointers
								return ptr == controller.getComputerVec()[i]->getNeighbors()[j];
							});
						// Adding the value only if it is not in the array
						if (it == controller.getComputerVec().end())
						{
							arr[index]++;
						}
					}
				}
			}
		}
	}
	return colorToCount(findMaxColor(arr));
}
//-------------------------------------------
//switch number into color
sf::Color Algorithm::colorToCount(int num)
{
	switch (num) {
	case 0:
		return sf::Color::Red;
	case 1:
		return sf::Color::Yellow;
	case 2:
		return sf::Color::Green;
	case 3:
		return sf::Color::Cyan;
	case 4:
		return sf::Color(255, 51, 153);
	case 5:
		return sf::Color(255, 128, 0);
	}
}
//------------------------------------------
//find the maximum color
int Algorithm::findMaxColor(int arr[])
{
	int max = arr[0];
	int index = 0;
	for (int i = 1; i < NUM_OF_COLORS; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}