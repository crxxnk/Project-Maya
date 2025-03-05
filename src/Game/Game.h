#pragma once
#include "../Settings/Settings.h"
#include "../Rendering/Renderer.h"
#include "../State/GameState.h"
#include "../Entity/Entity.h"
#include "../Player/Player.h"
#include "../AI/Npc.h"
#include "../Grid/Grid.h"
#include "../Editor/Editor.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Game {
	sf::Clock clock;
	EntityManager IDManager;
	sf::RenderWindow* window;
	Renderer renderer;

	std::vector<Entity*> entities;
	void spawnEntities(const std::vector<Entity*>& entities);
	void spawnEntity(Entity* entity);

	void render();
	void update(float deltaTime);
	void handleInput(float deltaTime);
public:
	Player* player;
	Settings settings;
	void run(sf::RenderWindow* window);
	Entity* getPlayer() { return entities.front(); }
	~Game();
};