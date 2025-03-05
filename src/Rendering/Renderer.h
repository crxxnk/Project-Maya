#pragma once
#include <SFML/Graphics.hpp>
#include "../Settings/Settings.h"
#include <iostream>

class Renderer {
public:
	sf::Font font;
	sf::RenderWindow* window;
	void draw(sf::RenderWindow* window, const Settings& settings);
	void drawText(std::string txt);
};