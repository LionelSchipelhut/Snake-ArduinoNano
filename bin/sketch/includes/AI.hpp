#ifndef __AI_HPP__
#define __AI_HPP__

#include <Arduino.h>
#include <avr/wdt.h>
#include "Keypad.hpp"

////////////////////////////////////////////////////
// Enum with the posible directions of SNAKE dot. //
////////////////////////////////////////////////////
enum SENSE {R_HORIZONTAL, L_HORIZONTAL, D_VERTICAL, U_VERTICAL};

////////////////////////////////////////
// Struct with the fields needed for  //
// each dot from the snake.           //
//    - X: Position in X of each dot. //
//    - Y: Position in Y of each dot. //
//    - sense: Sense of each dot.     //
////////////////////////////////////////
typedef struct {
    
    uint8_t X;
    uint8_t Y;
    SENSE sense;

}SNAKE;

//////////////////////////////////////////////
// Struct with the fields needed for the    //
// detection and drawing of the fruit.      //
//    - X: Position in X of the fruit.      //
//    - Y: Position in Y of the fruit.      //
//    - state: state of the fruit:          //
//                      + true: exist.      //
//                      + false: not exist. //
//////////////////////////////////////////////
typedef struct {

    uint8_t X;
    uint8_t Y;
    bool state;

}FRUIT;

//////////////////////////////////////
// Function that reset the arduino. //
//////////////////////////////////////
void reboot();

////////////////////////////////////////////////
// Class for managment of the automatization  //
// of functions such as generate the fruit or //
// create a new dot.                          //
////////////////////////////////////////////////
class AI {

    uint32_t it, ft;
    
    uint8_t snk_length;
    uint8_t moves_length;

    SENSE sense;
    KeyPad keypad;

    SNAKE *moves_row;
    SNAKE *snk;
    FRUIT fruit;

    ///////////////////////////////////////////////////
    // Reallocate the memory of an SNAKE type array. //
    ///////////////////////////////////////////////////
    SNAKE* reallocate(SNAKE *arr, uint8_t &old_length, uint8_t new_length);

    ////////////////////////////////////////////
    // Save the events for player movement of //
    // the snake.                             //
    ////////////////////////////////////////////
    bool saveEvent();

    ////////////////////////////////////////////
    // Change the sense of each dot if needed //
    // for player movement.                   //
    ////////////////////////////////////////////
    void changeSense(uint8_t i);

    /////////////////////////////////////
    // Add dynamicaly a new dot at the //
    // end of the snake.               //
    /////////////////////////////////////
    void addToSnake();

    ///////////////////////////////////////////
    // Extend the length of the snake array. //
    ///////////////////////////////////////////
    void createNewDot();

    ////////////////////////////////
    // Delete the fruit if exist. //
    ////////////////////////////////
    void killFruit();
    
    public:
        
        ////////////////////////
        // Class constructor. //
        ////////////////////////
        AI();

        ////////////////////////////////////////////////
        // Create all the initial dots for the snake. //
        ////////////////////////////////////////////////
        void begin(uint8_t snake_lenght);

        ///////////////////////////////////
        // Move the snake by the player. //
        ///////////////////////////////////
        void move();

        /////////////////////////////////////////
        // Keep the snake moving all the time. //
        /////////////////////////////////////////
        void walk();

        ////////////////////////////////////////////////
        // Generate a new fruit in a random position. //
        ////////////////////////////////////////////////
        void generateFruit();

        ////////////////////////////////////////////
        // If the fuit is eaten, delete this, add //
        // a new dot to the snake and generate    //
        // another fruit.                         //
        ////////////////////////////////////////////
        void fruitIsEaten();

        ///////////////////////////////////
        // If a button is pressed at the //
        // main screen, start the game.  //
        ///////////////////////////////////
        void startGame(bool &play);

        ////////////////////////////////////////////
        // Returns a pointer to the fruit object. //
        ////////////////////////////////////////////
        FRUIT* getFruit() {return &this->fruit;}
        
        //////////////////////////////////////////////////////
        // Returns a pointer to the array of snake objects. //
        //////////////////////////////////////////////////////
        SNAKE* getSnake() {return this->snk;}

        //////////////////////////////////////
        // Returns the value of snk_length. //
        //////////////////////////////////////
        uint8_t getSnkLength() {return this->snk_length;}

        ////////////////////////////////////////
        // Returns a reference to snk_length. //
        ////////////////////////////////////////
        uint8_t& getSnkLengthReference() {return this->snk_length;}

        //////////////////////////////////////////////
        // Returns a pointer to the array of moves. //
        //////////////////////////////////////////////
        SNAKE* getMoves() {return this->moves_row;}

        //////////////////////////////////////////
        // Returns a reference to moves_length. //
        //////////////////////////////////////////
        uint8_t& getMovesLengthReference() {return this->moves_length;}

};

#endif