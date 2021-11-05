//
// Created by Dylan Ray Roodt on 02.11.2021.
//

#include "APDS_Sensor.h"
#include <Arduino_APDS9960.h>

APDS_Sensor::APDS_Sensor() {

}

void APDS_Sensor::start() {
    if (APDS.begin()) {
        available = true;
    }
}

void APDS_Sensor::end() {
    APDS.end();
    available = false;
}

void APDS_Sensor::get_color(int& r, int& g, int& b) {
    if (!available) {
        return;
    }
    while (! APDS.colorAvailable()) {
        delay(2);
    }

    APDS.readColor(r, g, b);

}
int APDS_Sensor::get_light() {
    if (!available) {
        return 0;
    }
    while (! APDS.colorAvailable()) {
        delay(2);
    }

    int r, g, b, c;
    APDS.readColor(r, g, b, c);
    return c;
}

int APDS_Sensor::get_proximity() {
    if (!available) {
        return 0;
    }
    while (! APDS.colorAvailable()) {
        delay(2);
    }
    return APDS.readProximity();
}

int APDS_Sensor:: get_gesture() {
    if (!available) {
        return 0;
    }
    while (! APDS.colorAvailable()) {
        delay(2);
    }

    return APDS.readGesture();
}