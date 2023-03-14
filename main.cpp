/*/
g++ -std=c++17 main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o main -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system && ./main
/*/
#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.hpp"

int main() {
    auto window = sf::RenderWindow{sf::VideoMode(900, 1500), "CMake SFML Project" };
    window.setFramerateLimit(144);

    Player player(50, 50);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
            std::cout << "A key has been pressed" << std::endl;
        }
        window.clear(sf::Color::Black);
        player.drawto(window);
        window.display();
    }
}