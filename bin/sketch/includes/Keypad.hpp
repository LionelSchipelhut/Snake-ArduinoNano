#ifndef __KEYPAD_HPP__
#define __KEYPAD_HPP__

#include <Arduino.h>

#define Y0 5    //bit from register
#define Y1 6    //bit from register
#define X0 7    //bit from register
#define X1 0    //bit from register

////////////////////////////////////////
// Class for the managment of keypad. //
////////////////////////////////////////
class KeyPad {

    uint8_t mapping[2][2];
    uint32_t it, ft;

    //////////////////////////////////////////////////////
    // Function for read if a input keypad pin is high. //
    // Returns true if high, otherwise returns false.   //
    //////////////////////////////////////////////////////
    bool pinIsHigh(uint8_t pin);

    /////////////////////////////////////////////
    // Returns the correspondent value for the //
    // keypad mapping.                         //
    /////////////////////////////////////////////
    uint8_t event();

    public:

        ////////////////////////
        // Class constructor. //
        ////////////////////////
        KeyPad();

        /////////////////////////////////
        // Initialize the keypad pins. //
        /////////////////////////////////
        void begin();

        /////////////////////////////////////////
        // Returns the value from event() with //
        // the correspondent delay time within //
        // presses.                            //
        /////////////////////////////////////////
        uint8_t getEvent();
        
};

#endif