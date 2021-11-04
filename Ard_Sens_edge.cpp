//
// Created by Dylan Ray Roodt on 30.10.2021.
//
#include "Ard_Sens_edge.h"


Ard_Sense_edge::Ard_Sense_edge() {
    // Init
}

bool Ard_Sense_edge::begin() {
    Serial.println("Ard_Sense_edge::begin()");
    // Begin sensors
    bleHandler.begin();
    sensortec.begin();
    return true;
}

void Ard_Sense_edge::update() {
    // Update logic
    sensortec.update();
    bleHandler.update();
}

void Ard_Sense_edge::update(unsigned long ms) {
    update();
    delay(ms);
}

void Ard_Sense_edge::delay(unsigned long ms) {
    unsigned long start = millis();
    unsigned long elapsed = 0;
    while (elapsed < ms) {
        bleHandler.poll(ms - elapsed);
        elapsed = millis() - start;
    }
}

void Ard_Sense_edge::debug(Stream &stream)
{
  
    Serial.println("Ard_Sense_edge::debug()");
    _debug = &stream;
    BLEHandler::debug(stream);
}

Ard_Sense_edge Sens;
