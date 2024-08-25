Six Colors Hexagon Game
General Overview
The "Six Colors" game is a hexagonal strategy game involving two players: one human and one computer. The goal is to dominate the hexagonal board by capturing adjacent hexagons through color selection. The game leverages a graphical library to present an engaging and strategic experience. The computer opponent can be configured to follow different strategies—global greedy, local greedy, or random selection—adding depth and variability to the gameplay.

Project Structure and File Descriptions
Algorithm.cpp/hpp
This class is responsible for calculating the BFS algorithm and other auxiliary calculations used by the various computer players.
BaseComputer.cpp/hpp
An abstract base class inherited by three distinct computer players:
GlobalComputer
Represents the global greedy computer player who strategizes based on the entire board.
LocalComputer
Represents the local greedy player who selects the optimal move based on neighboring hexagons only.
RegularComputer
A random player that chooses one of the available colors at random.
Board.cpp/hpp
Manages the board, a vector of hexagonal cells. This class organizes the gameplay space and facilitates interactions between hexagons.
Hexagon.cpp/hpp
Holds a hexagon as an sf::CircleShape m_hexagon, storing its color and other attributes.
Cell.cpp/hpp
Contains a Hexagon member and stores a vector of neighboring hexagons, representing individual cells on the board.
Controller.cpp/hpp
Oversees the game's operations, handling objects and player interactions.
Display.cpp/hpp
Presents player selection options (Global, Local, or Random strategies).
Menu.cpp/hpp
Displays the available colors for players to choose from.
Player.cpp/hpp
Represents the human player in the game.
Utilities.cpp/hpp
Contains constants used throughout the program.
Key Data Structures
Cell
The Cell class contains the Hexagon class and holds a vector of neighbors.
Board
Contains a vector of Cell objects, effectively representing the game board.
Controller
Manages two key vectors:
std::vector<std::shared_ptr<Cell>> m_userVec
std::vector<std::shared_ptr<Cell>> m_computerVec
These vectors are populated by the BFS algorithm found in the Algorithm class, which examines the color paths, finding the longest chain of hexagons of the same color for the player.
Notable Algorithms
BFS (Breadth-First Search)
Utilized by the global greedy player to search for the optimal move across the entire board.

Random Color Selection
Used by the random player to choose a color without following a set strategy.

Local Greedy Color Selection
Focuses on a single cell, checking which color will yield the highest gain by examining only its six immediate neighbors, as opposed to the BFS that considers a wider range of neighbors.

Design
Class Hierarchy
The GlobalComputer, LocalComputer, and RegularComputer classes inherit from the BaseComputer class.
Relationships
The Cell class contains the Hexagon class, and both store additional vectors described above. These relationships help manage the connections and structure between the hexagonal cells on the board.
