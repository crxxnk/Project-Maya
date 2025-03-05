#include "Engine.h"

void Engine::run()
{
	window.create(sf::VideoMode({ 800, 600 }), "My window");
    while (window.isOpen())
    {
        if (currentState == GameState::EDITOR)
        {
            std::cout << "Starting Editor..." << std::endl;
            editor.run(&window);
        }
        else if (currentState == GameState::GAME)
        {
            std::cout << "Starting Game..." << std::endl;
            game.run(&window);
        }
    }
}