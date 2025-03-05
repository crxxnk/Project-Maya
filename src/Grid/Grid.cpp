#include "Grid.h"

Grid::Grid(int width, int height)
{
    for (int x = 0; x < width; ++x) {
        std::vector<Tile> column;
        for (int y = 0; y < height; ++y) {
            column.push_back(Tile(x * tileSize, y * tileSize, tileSize));
        }
        tiles.push_back(column);
    }
}

void Grid::draw(sf::RenderWindow* window)
{
    for (auto& column : tiles) {
        for (auto& tile : column) {
            tile.draw(window);
        }
    }
}

Tile* Grid::getTileAt(int x, int y)
{
    if (x >= 0 && x < tiles.size() && y >= 0 && y < tiles[0].size()) {
        return &tiles[x][y];
    }
    return nullptr;
}