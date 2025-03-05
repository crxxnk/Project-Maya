#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/EntityManager/EntityManager.h"
#include "../Entity/EntityType/EntityType.h"
#include <iostream>

class Entity
{
	uint32_t ID = 0;
public:
	EntityType type;
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool shouldBeRemoved = false;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;

	virtual void die();

	Entity(sf::Vector2f position, sf::Vector2f velocity, EntityType type) : position(position), velocity(velocity), type(type) {
		ID = EntityManager::getInstance().getNewID(type);
	}
	~Entity() { EntityManager::getInstance().freeID(ID); }
	unsigned int getID() const { return ID; }
};