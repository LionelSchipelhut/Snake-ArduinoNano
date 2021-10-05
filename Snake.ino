#include "includes/Graphics.hpp"
#include "includes/AI.hpp"

#define INIT_LEN 5
#define WIN_LEN 25

Screen screen;
AI ai;

bool play = false;

////////////////////////////////////
// Setup for all initializations. //
////////////////////////////////////
void setup() {

    Serial.begin(9600);
    screen.beginScreen();
    ai.begin(INIT_LEN);

    //screen.display();
    
}

////////////////
// Main loop. //
////////////////
void loop () {

    game();
    
}

//////////////////////////////////////////////////////////////////////////////
// Main function with al thos methods for showing and controlling the game. //
//////////////////////////////////////////////////////////////////////////////
void game() {

    if (ai.getSnkLength() == WIN_LEN) {
        play = screen.winScreen(ai.getSnake(), ai.getSnkLengthReference(), 
                                ai.getMoves(), ai.getMovesLengthReference());
    }

    if (!play) {

        ai.walk();
        screen.mainScreen(ai.getSnake(), ai.getSnkLength());
        ai.startGame(play);
    }
    else {
        ai.move();
        ai.walk();

        ai.generateFruit();
        ai.fruitIsEaten();

        Serial.println("Longitud: " + String(ai.getSnkLength()));

        screen.updateScreen(ai.getSnake(), ai.getSnkLength(), ai.getFruit());
    }

}
