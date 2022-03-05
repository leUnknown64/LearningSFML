#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include "Game.h"

int main(){
    // Init Game Engine
    Game game;

    // Game loop
    while(game.getWindowIsOpen()){
        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}