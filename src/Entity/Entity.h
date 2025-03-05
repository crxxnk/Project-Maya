#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/EntityManager/EntityManager.h"
#include "../Entity/EntityType/EntityType.h"
#include <iostream>

class Entity
{
	uint32_t ID;
public:
	ET::EntityType type;
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool shouldBeRemoved = false;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;

	virtual void die();

	Entity(sf::Vector2f position, sf::Vector2f velocity, ET::EntityType type) : position(position), velocity(velocity), type(type) {
		std::cout << "Entity created with type: " << std::hex << static_cast<uint32_t>(type) << "\n";
		ID = EntityManager::getInstance().getNewID(type);
	}
	~Entity() { EntityManager::getInstance().freeID(ID); }
	uint32_t getID() const { return ID; }
};