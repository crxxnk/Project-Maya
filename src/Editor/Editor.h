#pragma once
#include <SFML/Graphics.hpp>
#include "../State/GameState.h"
#include "../Settings/Settings.h"
#include "../Rendering/Renderer.h"
#include "../Grid/Grid.h"

class Editor {
	Grid grid;
	sf::RenderWindow* window;
	Renderer renderer;
	Settings settings;
	void render();
	void update();
	void handleInput();
	void handleEditorMouseClick(sf::RenderWindow* window, Grid* grid);
public:
	void run(sf::RenderWindow* window);
	Editor(int width = 20, int height = 15) : grid(width, height) {}
};