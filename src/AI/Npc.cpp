#include "Npc.h"

void NPC::update(float deltaTime)
{
    //float distance = length(player.getPosition() - position);
    //if (distance < 100) {  // If close, chase player
    //    velocity = normalize(player.getPosition() - position) * speed;
    //}
    //else {
    //    velocity = { 0, 0 };  // Stop moving if far
    //}
    //position += velocity * deltaTime;
}

void NPC::draw(sf::RenderWindow* window)
{

}

void NPC::die()
{
    std::cout << "NPC died" << std::endl;
    shouldBeRemoved = true;
}