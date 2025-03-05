#include "Entity.h"

void Entity::die()
{
	shouldBeRemoved = true;
	std::cout << "Entity " << getID() << " marked for removal\n";
}