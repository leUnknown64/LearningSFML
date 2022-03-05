#ifndef GAME_H
#define GAME_H

#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>

// Game engine class. Wrapper class.

class Game{
private:
    // Variables
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    // Game objects
    sf::RectangleShape enemy;

    // Member functions
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    Game();
    ~Game();

    // Accessors
    const bool getWindowIsOpen() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};

#endif