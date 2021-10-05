#include "includes/Graphics.hpp"

Screen::Screen()
: Adafruit_SSD1306(WIDTH, HEIGHT, &Wire, RESET){}

///////////////////////////////////
// Initialize Serial and address //
// and mode for SSD1306.         //
///////////////////////////////////
void Screen::beginScreen () {

    Serial.begin(9600);

    if (!this->begin(SSD1306_SWITCHCAPVCC, I2C_ADDR)) {

        Serial.println(F("Error initilizing SSD1306!"));

        while(1);
    }

    Serial.println(F("SSD1306 initialized!"));

    this->display();
    delay(2000);

    this->clearDisplay();

}

////////////////////////////////////
// Draw the frame on the borders. //
////////////////////////////////////
void Screen::drawFrame () {

    this->clearDisplay();

    this->drawLine(0, 0, 0, 63, SSD1306_WHITE);
    this->drawLine(0, 0, 127, 0, SSD1306_WHITE);
    this->drawLine(127, 0, 127, 63, SSD1306_WHITE);
    this->drawLine(0, 63, 127, 63, SSD1306_WHITE);

}
