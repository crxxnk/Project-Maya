#include "Renderer.h"

void Renderer::draw(sf::RenderWindow* window, const Settings &settings)
{
    this->window = window;

    sf::CircleShape circle(100.0f);
    circle.setFillColor(sf::Color::Cyan);
    this->window->setFramerateLimit(settings.maxFps);
    this->window->clear();
    this->window->draw(circle);
    this->window->display();
}

void Renderer::drawText(std::string txt)
{
    if(!font.openFromFile("assets/fonts/Roboto_Condensed-Regular.ttf"))
        std::cerr << "Failed to load font!" << std::endl;
    sf::Text text(font);
    text.setString(std::to_string(10));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    if(this->window->isOpen())
        this->window->draw(text);
}