#ifndef __IA_HPP__
#define __IA_HPP__

#include <Arduino.h>
#include <avr/wdt.h>
#include "Keypad.hpp"

enum SENSE {R_HORIZONTAL, L_HORIZONTAL, D_VERTICAL, U_VERTICAL};

typedef struct {
    
    uint8_t X;
    uint8_t Y;

}SNAKE;

void reboot();

class IA {

    uint32_t it, ft;
    
    uint8_t snk_length;
    uint8_t moves_length;

    SENSE sense;
    KeyPad keypad;

    public:

        SNAKE *snk;
        SNAKE *moves_row;
        
        IA();
        //~IA();

        void createNewDot();

        void move();

        void walk();

        uint8_t getSnkLength() {return this->snk_length;}
        
        static SNAKE* reallocate(SNAKE *arr, uint8_t &old_length, uint8_t new_length) {
            
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

};

#endif