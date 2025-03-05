#include "Editor.h"

void Editor::render()
{
    renderer.draw(this->window, settings);
}

void Editor::run(sf::RenderWindow* window)
{
	this->window = window;
    grid = Grid(20, 15);
    update();
}

void Editor::update()
{
    if (currentState == GameState::GAME) {
        
        return;
    }
    render();
    handleInput();
}

void Editor::handleInput()
{
    if (currentState == GameState::EDITOR)
        handleEditorMouseClick(window, &grid);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        if (currentState == GameState::PAUSED)
            currentState = GameState::EDITOR;
        else
            currentState = GameState::PAUSED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab)) {
        if (currentState != GameState::PAUSED && currentState == GameState::EDITOR) {
            currentState = GameState::GAME;
            std::cout << "Game State switched to " << currentState << std::endl;
            return;
        }
    }
}

void Editor::handleEditorMouseClick(sf::RenderWindow* window, Grid* grid) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    int tileX = mousePos.x / grid->tileSize;
    int tileY = mousePos.y / grid->tileSize;

    Tile* clickedTile = grid->getTileAt(tileX, tileY);
    if (clickedTile) {
        clickedTile->isOccupied = !clickedTile->isOccupied;
        clickedTile->shape.setFillColor(clickedTile->isOccupied ? sf::Color::Red : sf::Color::Green);
    }
}