#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Cell.h"
class Controller;
class Algorithm
{
public:

    ~Algorithm() = default;
    static Algorithm& getInstance();
    void bfs(std::vector<std::shared_ptr<Cell>>&, const sf::Color&);
    const sf::Color& LocalChoose(Controller& controller, bool colorHaveChoosed);
    const sf::Color& GlobalChoose(Controller& controller, bool colorHaveChoosed);
    void countColor(sf::Color color, int colorCounter[]);
    const sf::Color& globalColor(Controller& controller, bool colorHaveChoosed);
    sf::Color colorToCount(int num);
    int findMaxColor(int arr[]);

private:
    Algorithm();
    Algorithm(const Algorithm&) = default;//copy
    static Algorithm m_instance;
};