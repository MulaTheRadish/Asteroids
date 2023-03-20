#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define PI 3.14159265359

class Bullet {
    public:
        Bullet(sf::Vector2f position, float rotation) {
            sprite.setFillColor(sf::Color::White);
            sprite.setPosition(position);
            sprite.setRadius(3.5f);
            direction.x = terminalVelocity * sin(DegToRad(rotation));
            direction.y = terminalVelocity * -cos(DegToRad(rotation));
        }
        void shoot() {
            sprite.move(direction);
        }
        void draw(sf::RenderWindow &window) {
            window.draw(sprite);
        }
    private:
        sf::CircleShape sprite;
        sf::Vector2f position;
        sf::Vector2f direction;
        float terminalVelocity = 3.5f;

        float DegToRad(float degree) {
            return degree * (PI / 180);
        }
};