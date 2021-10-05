#include "includes/IA.hpp"

#define PERIOD 50
#define V 1

#define LEFT_EDGE 0x02
#define RIGHT_EDGE 0x7D
#define TOP_EDGE 0x02
#define BOT_EDGE 0x3D

void reboot() {

    wdt_disable();
    wdt_enable(WDTO_15MS);
    while(1);

}

IA::IA() {

    this->snk = new SNAKE[1];
    this->snk_length = 1;

    //this->moves_row = new SNAKE[1];
    this->moves_length = 0;

    this->sense = R_HORIZONTAL;

    this->it = 0;
    this->ft = this->it;

}

/*IA::~IA() {
    delete[] snk;
}*/

void IA::createNewDot() {
    
    this->snk = IA::reallocate(this->snk, this->snk_length, this->snk_length+1);

}

void IA::move() {

    
    
}

void IA::walk() {

    if (this->it == this->ft) {
        this->it = millis();
        this->ft = this->it + PERIOD;
        return;
    }
    
    this->it = millis();

    if (this->it > this->ft) {
        if (this->sense == R_HORIZONTAL) {
            for (uint8_t i=0; i<this->getSnkLength(); i++) {
                if ((this->snk + i)->X < RIGHT_EDGE) {
                    (this->snk+i)->X += V;
                }
                else {
                    (this->snk+i)->Y += V;
                    if (i == this->getSnkLength()-1) {this->sense = D_VERTICAL;}
                }
            }
        }
        else if (this->sense == L_HORIZONTAL) {
            for (uint8_t i=0; i<this->getSnkLength(); i++) {
                if ((this->snk + i)->X > LEFT_EDGE) {
                    (this->snk+i)->X -= V;
                }
                else {
                    (this->snk+i)->Y -= V;
                    if (i == this->getSnkLength()-1) {this->sense = U_VERTICAL;}
                }
            }
        }
        else if (this->sense == D_VERTICAL) {

            for (uint8_t i=0; i<this->getSnkLength(); i++) {
                if ((this->snk + i)->Y < BOT_EDGE) {
                    (this->snk+i)->Y += V;
                }
                else {
                    (this->snk+i)->X -= V;
                    if (i == this->getSnkLength()-1) {this->sense = L_HORIZONTAL;}
                }
            }
        }
        else if (this->sense == U_VERTICAL) {
            for (uint8_t i=0; i<this->getSnkLength(); i++) {
                if ((this->snk + i)->Y > TOP_EDGE) {
                    (this->snk+i)->Y -= V;
                }
                else {
                    (this->snk+i)->X += V;
                    if (i == this->getSnkLength()-1) {this->sense = R_HORIZONTAL;}
                }
            }
        }

        this->it = 0;
        this->ft = this->it;
    }

}