#include "includes/AI.hpp"

#define PERIOD 1
#define V 1

#define LEFT_EDGE 0x02
#define RIGHT_EDGE 0x7D
#define TOP_EDGE 0x02
#define BOT_EDGE 0x3D

//////////////////////////////////////
// Function that reset the arduino. //
//////////////////////////////////////
void reboot() {

    wdt_disable();
    wdt_enable(WDTO_15MS);
    while(1);

}

////////////////////////
// Class constructor. //
////////////////////////
AI::AI() {

    this->snk = new SNAKE[1];
    this->snk_length = 1;

    //this->moves_row = new SNAKE[1];
    this->moves_length = 0;

    this->sense = R_HORIZONTAL;

    this->it = 0;
    this->ft = this->it;

}

////////////////////////////////////////////////
// Create all the initial dots for the snake. //
////////////////////////////////////////////////
void AI::begin(uint8_t snake_lenght) {

    uint8_t x = 0x03;

    keypad.begin();

    for (uint8_t i=0; i<snake_lenght-1; i++) {
        this->createNewDot();
    }

    for (int8_t i=this->getSnkLength()-1; i>=0; i--) {
        (this->snk+i)->X = x;
        (this->snk+i)->Y = 0x03;
        (this->snk+i)->sense = R_HORIZONTAL;

        x++;
    }

    this->killFruit();

}

///////////////////////////////////////////////////
// Reallocate the memory of an SNAKE type array. //
///////////////////////////////////////////////////
SNAKE* AI::reallocate(SNAKE *arr, uint8_t &old_length, uint8_t new_length) {
            
            Serial.println(F("Reallocating..."));

            SNAKE *arr2 = NULL;
            
            arr2 = new SNAKE[new_length];

            if (arr2 == NULL) {
                Serial.println("Reallocation failed!");
                reboot();
            }
            
            for (uint8_t i=0; i<old_length; i++) {
                *(arr2+i) = *(arr+i);
            }

            delete[] arr;

            old_length = new_length;

            return arr2;
        }

///////////////////////////////////////////
// Extend the length of the snake array. //
///////////////////////////////////////////
void AI::createNewDot() {
    
    Serial.println(F("New Dot..."));

    this->snk = this->reallocate(this->snk, this->snk_length, this->snk_length+1);

}

///////////////////////////////////
// Move the snake by the player. //
///////////////////////////////////
void AI::move() {

    this->saveEvent();

    if (this->moves_length <= 0) return;
    
    for (uint8_t i=0; i<this->moves_length; i++) {
        
        this->changeSense(i);
    }

    if ((this->snk+this->snk_length-1)->X == (this->moves_row+this->moves_length-1)->X &&
        (this->snk+this->snk_length-1)->Y == (this->moves_row+this->moves_length-1)->Y) {

        delete[] moves_row;
        this->moves_length = 0;
        Serial.println("Borrando. moves_length = " + String(this->moves_length));

    }
 
}

/////////////////////////////////////////
// Keep the snake moving all the time. //
/////////////////////////////////////////
void AI::walk() {

    if (this->it == this->ft) {
        this->it = millis();
        this->ft = this->it + PERIOD;
        return;
    }
    
    this->it = millis();

    if (this->it > this->ft) {
        for (uint8_t i=0; i<this->getSnkLength(); i++) {
            if ((this->snk + i)->sense == R_HORIZONTAL) {
                if ((this->snk + i)->X < RIGHT_EDGE) {
                    (this->snk+i)->X += V;
                }
                else {
                    (this->snk+i)->Y += V;
                    (this->snk + i)->sense = D_VERTICAL;
                }
            }
            else if ((this->snk + i)->sense == L_HORIZONTAL) {
                if ((this->snk + i)->X > LEFT_EDGE) {
                    (this->snk+i)->X -= V;
                }
                else {
                    (this->snk+i)->Y -= V;
                    (this->snk + i)->sense = U_VERTICAL;
                }
            }
            else if ((this->snk + i)->sense == D_VERTICAL) {
                if ((this->snk + i)->Y < BOT_EDGE) {
                    (this->snk+i)->Y += V;
                }
                else {
                    (this->snk+i)->X -= V;
                    (this->snk + i)->sense = L_HORIZONTAL;
                }
            }
            else if ((this->snk + i)->sense == U_VERTICAL) {
                if ((this->snk + i)->Y > TOP_EDGE) {
                    (this->snk+i)->Y -= V;
                }
                else {
                    (this->snk+i)->X += V;
                    (this->snk + i)->sense = R_HORIZONTAL;
                }
            }
        }

        this->it = 0;
        this->ft = this->it;
    }

}

////////////////////////////////////////////
// Change the sense of each dot if needed //
// for player movement.                   //
////////////////////////////////////////////
void AI::changeSense(uint8_t j) {

    for (uint8_t i=0; i<this->getSnkLength(); i++) {
        if ((this->snk + i)->sense == R_HORIZONTAL) {
            if ((this->snk + i)->X == (this->moves_row+j)->X) {
                (this->snk + i)->sense = (this->moves_row+j)->sense;
            }
        }
        else if ((this->snk + i)->sense == L_HORIZONTAL) {
            if ((this->snk + i)->X == (this->moves_row+j)->X) {
                (this->snk + i)->sense = (this->moves_row+j)->sense;
            }
        }
        else if ((this->snk + i)->sense == D_VERTICAL) {
            if ((this->snk + i)->Y == (this->moves_row+j)->Y) {
                (this->snk + i)->sense = (this->moves_row+j)->sense;
            }
        }
        else if ((this->snk + i)->sense == U_VERTICAL) {
            if ((this->snk + i)->Y == (this->moves_row+j)->Y) {
                (this->snk + i)->sense = (this->moves_row+j)->sense;
            }
        }
    }

}

////////////////////////////////////////////
// Save the events for player movement of //
// the snake.                             //
////////////////////////////////////////////
bool AI::saveEvent() {

    uint8_t event;

    event = keypad.getEvent();
    if (event == 4) return false;

    Serial.println(F("Saving event..."));

    if (this->moves_length == 0) {
        this->moves_row = new SNAKE[1];
        this->moves_length++;

        if (event == 0b00) {
            (this->moves_row + moves_length-1)->sense = U_VERTICAL;
        }
        else if (event == 0b01) {
            (this->moves_row + moves_length-1)->sense = L_HORIZONTAL;
        }
        else if (event == 0b10) {
            (this->moves_row + moves_length-1)->sense = R_HORIZONTAL;
        }
        else if (event == 0b11) {
            (this->moves_row + moves_length-1)->sense = D_VERTICAL;
        }

        (this->moves_row + moves_length-1)->X = this->snk->X;
        (this->moves_row + moves_length-1)->Y = this->snk->Y;

        return true;
    }

    this->moves_row = this->reallocate(this->moves_row, this->moves_length, this->moves_length+1);
    
    if (event == 0b00) {
        (this->moves_row + moves_length-1)->sense = U_VERTICAL;
    }
    else if (event == 0b01) {
        (this->moves_row + moves_length-1)->sense = L_HORIZONTAL;
    }
    else if (event == 0b10) {
        (this->moves_row + moves_length-1)->sense = R_HORIZONTAL;
    }
    else if (event == 0b11) {
        (this->moves_row + moves_length-1)->sense = D_VERTICAL;
    }

    (this->moves_row + moves_length-1)->X = this->snk->X;
    (this->moves_row + moves_length-1)->Y = this->snk->Y;

    return true;

}

////////////////////////////////////////////////
// Generate a new fruit in a random position. //
////////////////////////////////////////////////
void AI::generateFruit() {

    if (fruit.state) return;

    this->fruit.X = (uint8_t)random(LEFT_EDGE+1, RIGHT_EDGE-1);
    this->fruit.Y = (uint8_t)random(TOP_EDGE+1, BOT_EDGE-1);
    this->fruit.state = true;

}

////////////////////////////////
// Delete the fruit if exist. //
////////////////////////////////
void AI::killFruit() {

    this->fruit.X = 0;
    this->fruit.Y = 0;
    this->fruit.state = false;

}

////////////////////////////////////////////
// If the fuit is eaten, delete this, add //
// a new dot to the snake and generate    //
// another fruit.                         //
////////////////////////////////////////////
void AI::fruitIsEaten() {

    if (this->snk->X == this->fruit.X &&
        this->snk->Y == this->fruit.Y) {
        
        Serial.println(F("Fruit eaten."));

        this->killFruit();
        this->addToSnake();

    }

}

/////////////////////////////////////
// Add dynamicaly a new dot at the //
// end of the snake.               //
/////////////////////////////////////
void AI::addToSnake() {

    this->createNewDot();

    (this->snk+this->snk_length-1)->sense = (this->snk+this->snk_length-2)->sense;

    if ((this->snk + this->snk_length-1)->sense == R_HORIZONTAL) {
        (this->snk + this->snk_length-1)->X = (this->snk + this->snk_length-2)->X - 1;
        (this->snk + this->snk_length-1)->Y = (this->snk + this->snk_length-2)->Y;
    }
    else if ((this->snk + this->snk_length-1)->sense == L_HORIZONTAL) {
        (this->snk + this->snk_length-1)->X = (this->snk + this->snk_length-2)->X + 1;
        (this->snk + this->snk_length-1)->Y = (this->snk + this->snk_length-2)->Y;
    }
    else if ((this->snk + this->snk_length-1)->sense == D_VERTICAL) {
        (this->snk + this->snk_length-1)->X = (this->snk + this->snk_length-2)->X;
        (this->snk + this->snk_length-1)->Y = (this->snk + this->snk_length-2)->Y - 1;
    }
    else if ((this->snk + this->snk_length-1)->sense == U_VERTICAL) {
        (this->snk + this->snk_length-1)->X = (this->snk + this->snk_length-2)->X;
        (this->snk + this->snk_length-1)->Y = (this->snk + this->snk_length-2)->Y + 1;
    }

}

///////////////////////////////////
// If a button is pressed at the //
// main screen, start the game.  //
///////////////////////////////////
void AI::startGame(bool &play) {

    uint8_t event = keypad.getEvent();

    if (event != 4) {
        play = true;
        return;
    }

    play = false;

}

