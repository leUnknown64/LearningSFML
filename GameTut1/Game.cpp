#include "Game.h"

// Private Functions
// Initializes a pointer to our game window
void Game::initVariables(){
    window = nullptr;
}

// Initializes the window's resolution, then dynamically allocates a window
void Game::initWindow(){
    // Resolution
    videoMode.height = 600;
    videoMode.width = 800;

    window = new sf::RenderWindow(videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(60); // FPS Limit
}

// Responsible for creating an enemy
void Game::initEnemies(){
    // Set enemy's position
    enemy.setPosition(100.f, 100.f);

    // Set enemy's size 
    enemy.setSize(sf::Vector2f(50.f, 50.f));    
    
    // Set enemy's color
    enemy.setFillColor(sf::Color::Red); 
    enemy.setOutlineColor(sf::Color::Red);
    enemy.setOutlineThickness(1.f);
}

// Public Functions
// Constructor
Game::Game(){
    initVariables();
    initWindow();
    initEnemies();
}

// Deconstructor
Game::~Game(){
    delete window; // delete window from heap memory
}

// Accessors
// Verify that the game window is open
const bool Game::getWindowIsOpen() const{
    return window->isOpen();
}

// Event polling - handle closing the window
void Game::pollEvents(){
    while(this->window->pollEvent(ev)){
        switch(ev.type){
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if(ev.key.code == sf::Keyboard::Escape){
                window->close();
            }
            break;
        }
    }
}

// Functions
// Updates on every frame
void Game::update(){
    pollEvents();

    // Update mouse position relative to game window
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << std::endl;
}

// Renders game objects
void Game::render(){
    window->clear(); // Clear old frame

    // Draw game objects
    window->draw(enemy);

    window->display(); // Display drawn objects
}
