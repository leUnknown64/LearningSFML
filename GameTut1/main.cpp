#include<cstdlib>
#include<ctime>
#include "Game.h"

int main(){
    // Init srand
    srand(time(NULL));

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