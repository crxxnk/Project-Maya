#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
    sf::RectangleShape shape;
    bool isOccupied = false;

    Tile(float x, float y, float size);

    void draw(sf::RenderWindow* window);
};