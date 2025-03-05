#pragma once
#include <SFML/Graphics.hpp>
#include "../Settings/Settings.h"
#include "../State/GameState.h"
#include "../Game/Game.h"
#include "../Editor/Editor.h"

class Engine {
	sf::RenderWindow window;
	Game game;
	Editor editor;
public:
	void run();
};