#include <SFML/Graphics.hpp>
#include <iostream>

#include "spaceship.hpp"
#include "bullet.hpp"

int main()
{
    auto window = sf::RenderWindow{sf::VideoMode(800, 1200), "Asteroids"};
    window.setFramerateLimit(144);

    Spaceship spaceship;
    spaceship.loadTexture("spaceship.png", window.getSize().x / 2, window.getSize().y / 2);
    std::vector<Bullet> bulletVector;
    bool isFiring;

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                spaceship.userInput(event.key.code, true);
                if (event.key.code == sf::Keyboard::Space) {
                    isFiring = true;
                }
            }
            if (event.type == sf::Event::KeyReleased) {
                spaceship.userInput(event.key.code, false);
            }
        }

        window.clear();
        if (isFiring == true) {
            Bullet bullet(spaceship.sprite.getPosition(), spaceship.sprite.getRotation());
            bulletVector.push_back(bullet);
            isFiring = false;
        }
        for (int i = 0; i < bulletVector.size(); i++) {
            bulletVector[i].draw(window);
            bulletVector[i].shoot();
        }
        spaceship.movement();
        spaceship.draw(window);
        window.display();
    }
}