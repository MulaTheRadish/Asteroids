//g++ -std=c++17 main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o main -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system && ./main
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //Rendering window
    auto window = sf::RenderWindow{sf::VideoMode(500, 500), "CMake SFML Project" };
    window.setFramerateLimit(144);
    
    //Importing Spaceship I.e. player sprite
    sf::Texture spaceshipTexture; 
    if (!spaceshipTexture.loadFromFile("spaceship.png")) {
        std::cout << "Failed to load Spaceship.png" << std::endl;
        return 0;
    }
    sf::Sprite shipSprite;
    shipSprite.setTexture(spaceshipTexture); 
    shipSprite.setPosition(sf::Vector2f(250, 250));
    shipSprite.scale(sf::Vector2f(0.15, 0.15));

    //Game Loop
    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(shipSprite);
        window.display();
    }
}