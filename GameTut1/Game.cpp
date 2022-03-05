#include "Game.h"

// Private Functions
// Initializes private variables
void Game::initVariables(){
    window = nullptr; // Initialize our window pointer

    // Initialize game logic variables
    points = 0;
    
    // Spawn timer for enemies
    enemySpawnTimerMax = 30.f;
    enemySpawnTimer = enemySpawnTimerMax;
    
    maxEnemies = 15;
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
    // Set enemy's size 
    enemy.setSize(sf::Vector2f(50.f, 50.f));    
    
    // Set enemy's color
    enemy.setFillColor(sf::Color::Red);
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


// Spawning objects
// Creates a new randomized enemy and adds it to enemies
void Game::spawnEnemy(){
    // Set a random spawn position
    enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
        0.f
        //static_cast<float>(rand() % static_cast<int>(window->getSize().y - enemy.getSize().y))
    );

    // Set a random color - will come back to

    // Push created enemy to enemies vector
    enemies.push_back(enemy);
}

// Updates
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

// Updates mouse positions: 
// 1. Position relative to window (Vector2i)
void Game::updateMousePositions(){
    mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);
}

// Updates enemies by
// 1. Keeping track of the enemy spawn timer and spawning enemies
// 2. Ensuring there are less enemies then the maximum amount
// 3. Moving enemies on the screen
// 4. Remove enemies at the edge of the screen
// 5. Remove enemies that are left-clicked
void Game::updateEnemies(){
    // Updates the enemy spawn timer and spawns enemies until the maximum amount is reached.
    if(enemies.size() < maxEnemies){
        if(enemySpawnTimer >= enemySpawnTimerMax){
            // Spawn in an enemy and reset the timer to 0
            spawnEnemy(); 
            enemySpawnTimer = 0.f;
        }
        else{
            enemySpawnTimer += 1.f;
        }
    }

    // Move enemies downward
    bool deleted = false; // If enemy is to be deleted
    for(int i = 0; i < enemies.size(); i++){
        deleted = false;

        enemies[i].move(0.f, 5.f);

        // Check if an enemy is clicked, if so delete it
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(enemies[i].getGlobalBounds().contains(mousePosView)){
                deleted = true;

                // Earn points
                points += 10;
            }
        }

        // Remove enemies at the bottom of the screen
        if(enemies[i].getPosition().y > window->getSize().y){
            deleted = true;
        }

        // Final delete from enemies vector
        if(deleted){
            enemies.erase(enemies.begin() + i);
        }
    }
}

// Updates the following on every frame:
// 1. Event polling2
// 2. Mouse positions
// 3. Game objects
void Game::update(){
    pollEvents();
    updateMousePositions();
    updateEnemies();
}


// Rendering
// Renders all enemies spawned
void Game::renderEnemies(){
    for(auto &e : enemies){
        window->draw(e);
    }
}

// Master render function responsible for
// 1. Clearing the previous frame
// 2. Rendering game objects
// 3. Displaying rendered objects on the next frame
void Game::render(){
    window->clear();

    renderEnemies();

    window->display(); 
}
