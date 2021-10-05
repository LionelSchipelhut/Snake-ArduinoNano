#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Fonts.h"

#define WIDTH 0x80
#define HEIGHT 0x40
#define RESET 4
#define I2C_ADDR 0x3D

///////////////////////////////////////////////////
// Class for the managment of graphics functions //
// for displaying the game.                      //
///////////////////////////////////////////////////
class Screen : public Adafruit_SSD1306 {

    public:
        ////////////////////////
        // Class constructor. //
        ////////////////////////
        Screen();

        ///////////////////////////////////
        // Initialize Serial and address //
        // and mode for SSD1306.         //
        ///////////////////////////////////
        void beginScreen();

        ////////////////////////////////////
        // Draw the frame on the borders. //
        ////////////////////////////////////
        void drawFrame();

        /////////////////////////////
        // Update the game screen. //
        /////////////////////////////
        template <class T, class U>
        void updateScreen(T *snake, uint8_t length, U *fruit);

        /////////////////////////////////////////////
        // Shows the main screen with play option. //
        /////////////////////////////////////////////
        template <class T>
        void Screen::mainScreen(T *snake, uint8_t length);

        //////////////////////////////////////////////////////////////////
        // Shows the screen win screen, liberate all the dinamic memory //
        // and reset all the length counters.                           //
        //////////////////////////////////////////////////////////////////
        template <class T>
        bool winScreen(T *snake, uint8_t &snk_length, T *moves, uint8_t &moves_length);
};

template <class T, class U>
void Screen::updateScreen(T *snake, uint8_t length, U *fruit) {

    this->clearDisplay();

    this->drawFrame();

    for (uint8_t i=0; i<length; i++) {
        this->fillRect((snake+i)->X, (snake+i)->Y, 2, 2, SSD1306_WHITE);
    }

    if (fruit->state) {this->fillRect(fruit->X, fruit->Y, 2, 2, SSD1306_WHITE);}
    else {this->fillRect(fruit->X, fruit->Y, 2, 2, SSD1306_BLACK);}

    this->display();

}

template <class T>
void Screen::mainScreen(T *snake, uint8_t length) {

    this->clearDisplay();

    this->drawFrame();

    this->setTextColor(SSD1306_WHITE);
    this->setFont(&Roboto_10);
    this->setTextSize(1);
    this->setCursor(50, 50);

    this->println("PLAY");

    for (uint8_t i=0; i<length; i++) {
        this->fillRect((snake+i)->X, (snake+i)->Y, 2, 2, SSD1306_WHITE);
    }

    this->display();

}

template <class T>
bool Screen::winScreen(T *snake, uint8_t &snk_length, T *moves, uint8_t &moves_length) {

    this->clearDisplay();

    this->drawFrame();

    this->setTextColor(SSD1306_WHITE);
    this->setFont(&Roboto_10);
    this->setTextSize(1);
    this->setCursor(30, 30);

    this->println("YOU'VE WIN");

    delete[] snake;
    delete[] moves;

    snk_length = 0;
    moves_length = 0;

    this->display();

    delay(5000);

}

#endif