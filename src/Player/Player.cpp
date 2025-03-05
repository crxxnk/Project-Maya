#include "Player.h"

void Player::update(float deltaTime)
{
    std::cout << "Player update called!" << std::endl;
    handleInput(deltaTime);
}

void Player::draw(sf::RenderWindow* window)
{

}

void Player::die()
{
	std::cout << "Player died " << getID() <<std::endl;
}

void Player::handleInput(float deltaTime)
{
    float moveSpeed = 200.0f; // Pixels per second

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        position.y += moveSpeed * deltaTime;
        std::cout << position.y << " ";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        position.y -= moveSpeed * deltaTime;
        std::cout << position.y << " ";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        position.x -= moveSpeed * deltaTime;
        std::cout << position.x << " ";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        position.x += moveSpeed * deltaTime;
        std::cout << position.x << " ";
    }
}