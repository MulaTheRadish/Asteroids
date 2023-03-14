#include <SFML/Graphics.hpp>

class Player {
    public:
        Player(float x, float y) {
            rect.setSize(sf::Vector2f(x, y));
        }
        void drawto(sf::RenderWindow &window) {
            window.draw(rect);
        }

    private:
        sf::RectangleShape rect;
};