#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define PI 3.14159265359

class Spaceship {
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f direction;

        void loadTexture(std::string fileName, float x, float y) {
            if (!texture.loadFromFile(fileName)) {
                std::cout << "Error loading " << fileName << std::endl;;
            }
            sprite.setTexture(texture);
            sprite.setScale(sf::Vector2f(0.2, 0.2));
            sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
            sprite.setPosition(x, y);
        }
        void userInput(sf::Keyboard::Key key, bool checkPressed) {
            if (checkPressed == true) {
                if (key == sf::Keyboard::Up || key == sf::Keyboard::W) {
                    up = true;
                }
                if (key == sf::Keyboard::Down || key == sf::Keyboard::S) {
                    down = true;
                }
                if (key == sf::Keyboard::Left || key == sf::Keyboard::A) {
                    left = true;
                }
                if (key == sf::Keyboard::Right || key == sf::Keyboard::D) {
                    right = true;
                }
            }
            else {
                if (key == sf::Keyboard::Up || key == sf::Keyboard::W) {
                    up = false;
                }
                if (key == sf::Keyboard::Down || key == sf::Keyboard::S) {
                    down = false;
                }
                if (key == sf::Keyboard::Left || key == sf::Keyboard::A) {
                    left = false;
                }
                if (key == sf::Keyboard::Right || key == sf::Keyboard::D) {
                    right = false;
                }
            }
        }
        void movement() {
            direction.x = terminalVelocity * sin(DegToRad(sprite.getRotation()));
            direction.y = terminalVelocity * -cos(DegToRad(sprite.getRotation()));

            if (up == true) {
                sprite.move(direction.x, direction.y);
            }
            if (down == true) {
                sprite.move(-direction.x, -direction.y);
            }
            if (right == true) {
                sprite.rotate(terminalRotation);
            }
            if (left == true) {
                sprite.rotate(-terminalRotation);
            }
        }
        void draw(sf::RenderWindow &window) {
            window.draw(sprite);
        }
    private:
        float terminalVelocity = 2.f;
        float terminalRotation = 2.f;
        bool up, down, left, right;
    
        float DegToRad(float degree) {
            return degree * (PI / 180);
        }
};