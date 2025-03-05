#include "Tile.h"

Tile::Tile(float x, float y, float size)
{
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(sf::Color::Green);  // You can change the color later
}

void Tile::draw(sf::RenderWindow* window)
{
    window->draw(shape);
}