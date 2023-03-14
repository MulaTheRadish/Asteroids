#include <SFML/Graphics.hpp>
#include <iostream>

#include "spaceship.hpp"

int main()
{
    auto window = sf::RenderWindow{sf::VideoMode(800, 1200), "Asteroids"};
    window.setFramerateLimit(144);

    Spaceship spaceship;
    spaceship.loadTexture(400, 600);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                spaceship.eventKey(event.key.code, true);
            }
            if (event.type == sf::Event::KeyReleased) {
                spaceship.eventKey(event.key.code, false);
            }
        }
        
        window.clear(sf::Color::Black);
        spaceship.update();
        spaceship.drawto(window);
        window.display();
    }
}