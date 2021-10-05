#include "includes/Keypad.hpp"
#include <avr/io.h>

#define DELAY 50
#define WAIT 100

////////////////////////
// Class constructor. //
////////////////////////
KeyPad::KeyPad() : mapping{{0b00, 0b01},        //{UP, RIGHT}
                           {0b10, 0b11}} {}     //{LEFT, DOWN}

/////////////////////////////////
// Initialize the keypad pins. //
/////////////////////////////////
void KeyPad::begin() {

    DDRD &= ~(1<<Y0) & ~(1<<Y1);
    DDRD |= (1<<X0);
    DDRB |= (1<<X1);

    this->it = 0;
    this->ft = this->it;

}

/////////////////////////////////////////
// Returns the value from event() with //
// the correspondent delay time within //
// presses.                            //
/////////////////////////////////////////
uint8_t KeyPad::getEvent() {

    if (this->it == this->ft) {
        this->it = millis();
        this->ft = this->it + WAIT;
        return 4;
    }

    this->it = millis();

    if (this->it > this->ft) {

        this->it = 0;
        this->ft = this->it;

        return this->event();

    }

    return 4;
    
}

/////////////////////////////////////////////
// Returns the correspondent value for the //
// keypad mapping.                         //
/////////////////////////////////////////////
uint8_t KeyPad::event() {
    
    PORTD |= (1<<X0);
    PORTB &= ~(1<<X1);

    if (pinIsHigh(Y0)) return mapping[0][0];
    else if (pinIsHigh(Y1)) return mapping[0][1];

    delay(DELAY);

    PORTB |= (1<<X1);
    PORTD &= ~(1<<X0);

    if (pinIsHigh(Y0)) return mapping[1][0];
    else if (pinIsHigh(Y1)) return mapping[1][1];

    delay(DELAY);

    return 4;

}

//////////////////////////////////////////////////////
// Function for read if a input keypad pin is high. //
// Returns true if high, otherwise returns false.   //
//////////////////////////////////////////////////////
bool KeyPad::pinIsHigh(uint8_t pin) {

    if(PIND & (1<<pin)) return true;

    return false;

}