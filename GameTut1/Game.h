#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>
#include<cstdlib>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>

// Game engine class. Wrapper class.

class Game{
private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    // Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    unsigned int maxEnemies;

    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    // Member functions
    // Initializers
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    Game();
    ~Game();

    // Accessors
    const bool getWindowIsOpen() const;

    // Member Functions
    // Spawning objects
    void spawnEnemy();

    // Updates
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();

    // Rendering
    void renderEnemies();
    void render();
};

#endif