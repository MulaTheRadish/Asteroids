#include <SFML/Graphics.hpp>
#include <iostream>

class Spaceship {
    public:
        void loadTexture(int x, int y) {
            if (!playerTexture.loadFromFile("spaceship.png")) {
                std::cout << "Failed to load spaceship.png" << std::endl;
                return;
            }
            playerSprite.setTexture(playerTexture);

            up = false;
            down = false;
            right = false;
            left = false;

            playerSprite.setPosition(sf::Vector2f(x, y));
            playerSprite.scale(sf::Vector2f(0.2, 0.2));
        }
        void drawto(sf::RenderWindow &window) {
            window.draw(playerSprite);
        }
        void eventKey(sf::Keyboard::Key key, bool checkPressed) {
            if (checkPressed == true) {
                if (key == sf::Keyboard::Key::W) {
                    up = true;
                }
                else if (key == sf::Keyboard::Key::S) {
                    down = true;
                }
                else if (key == sf::Keyboard::Key::A) {
                    right = true;
                }
                else if (key == sf::Keyboard::Key::D) {
                    left = true;
                }
            }
            else {
                up = false;
                down = false;
                right = false;
                left = false;
            }
        }
        void update() {
            sf::Vector2f movement;
            if (up) {
                movement.y += -2.0f;
            }
            if (down) {
                movement.y += 2.0f;
            }
            if (right) {
                movement.x += -2.0f;
            }
            if (left) {
                movement.x += 2.0f;
            }
            playerSprite.move(movement);
        }
    private:
        sf::Texture playerTexture;
        sf::Sprite playerSprite;

        bool up, down, right, left;
};