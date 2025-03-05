#pragma once
#include "../Entity/Entity.h"

class Player : public Entity
{
	bool isAlive = true;
public:
	EntityType type = PLAYER;
	Player(sf::Vector2f position, sf::Vector2f velocity) : Entity(position, velocity, type) {}
	void update(float deltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void die() override;
	bool getIsAlive() const { return isAlive; }
	void handleInput(float deltaTime);
};