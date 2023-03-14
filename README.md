# Asteroids
A simple program replicating the video game "Asteroids" in C++ utilising the SFML library to demonstrate my proficiency in C++. 

## How to start the video game

The video game was coded in the following environment: 
* [SFML version 2.5.1_2](https://www.sfml-dev.org/download/sfml/2.5.1/)
* Visual Studio Code
* MacOS Ventura 13.1 w/ Apple M2

### Using homebrew SFML

SFML was installed using homebrew. In order to run the code, the include and lib files of the SFML library must be added in the command used to run the program followed by several additional parameters including `-lsfml-graphics`, `-lsfml-window`, and `-lsfml-system`. Finally followed by running the output program `./main`.

It was run through this command in the vscode terminal:
```
g++ -std=c++17 main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o main -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system && ./main
```