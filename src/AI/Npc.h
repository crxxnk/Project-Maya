#pragma once
#include "../Entity/Entity.h"
#include "../Player/Player.h"

class NPC : public Entity
{
	bool isAlive = true;
public:
	NPC(sf::Vector2f position, sf::Vector2f velocity) : Entity(position, velocity, ET::EntityType::NPC) {}
	void update(float deltaTime);
	void draw(sf::RenderWindow* window) override;
	bool getIsAlive() const { return isAlive; }
	void die();
};