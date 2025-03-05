#include "Game.h"

void Game::spawnEntities(const std::vector<Entity*>& entities)
{
    for(auto &entity : entities)
        this->entities.push_back(entity);
}

void Game::spawnEntity(Entity* entity)
{
    this->entities.push_back(entity);
}

void Game::render()
{
    renderer.draw(this->window, settings);
    renderer.drawText(std::to_string(currentState));
    for (auto entity : entities)
        entity->draw(window);
}

void Game::run(sf::RenderWindow* window)
{
    player = new Player({ 10, 10 }, { 10, 10 });
    std::cout << "Player: " << player->getID() << std::endl;
    entities.push_back(player);
    spawnEntity(new NPC({ 10, 10 }, { 10, 10 }));
    spawnEntity(new NPC({ 10, 10 }, { 10, 10 }));
    spawnEntity(new NPC({ 10, 10 }, { 10, 10 }));
    spawnEntity(new NPC({ 10, 10 }, { 10, 10 }));
    this->window = window;
    while (this->window->isOpen() && currentState == GameState::GAME)
    {
        while (const std::optional event = this->window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                this->window->close();
        }

        std::cout << "Window is open" << std::endl;
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}

void Game::update(float deltaTime)
{
    handleInput(deltaTime);
    if (currentState == GameState::EDITOR)
        return;

    std::cout << "Game updating" << std::endl;

    for (auto& entity : entities) {
        if (entity) {
            entity->update(deltaTime);
        }
    }

    if (!entities.empty()) {
        for (auto& entity : entities)
            entity->die();
    }

    for (auto it = entities.begin(); it != entities.end(); ) {
        Entity* entity = *it;

        if (entity->shouldBeRemoved && entity->getID() != 0) {
            IDManager.freeID(entity->getID());
            std::cout << entity->getID() << "returned to pool!" << std::endl;
            delete entity;
            it = entities.erase(it);
        }
        else {
            ++it;
        }
    }

    std::cout << "Entities: ";
    for (auto entity : entities) {
        std::cout << std::hex << std::showbase << entity->getID() << " ";
        entity->update(deltaTime);
    }
    std::cout << std::endl;
}

void Game::handleInput(float deltaTime)
{
    if (currentState == GameState::GAME) {
        if (player)
            player->update(deltaTime);
        else
            std::cerr << "Couldn't find player" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        std::cout << "Escape pressed" << std::endl;
        if (currentState == GameState::PAUSED)
            currentState = GameState::GAME;
        else
            currentState = GameState::PAUSED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Tab))
    {
        if (currentState != GameState::PAUSED) {
            currentState = GameState::EDITOR;
            std::cout << "Game State switched to " << currentState << std::endl;
            return;
        }
    }
}

Game::~Game() {
    for (auto entity : entities)
        delete entity;
    entities.clear();
}