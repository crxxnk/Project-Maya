#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

struct Grid {
public:
    std::vector<std::vector<Tile>> tiles;
    float tileSize = 32.0f;

    Grid(int width, int height);

    void draw(sf::RenderWindow* window);

    Tile* getTileAt(int x, int y);
};