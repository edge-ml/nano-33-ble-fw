//
// Created by Dylan Ray Roodt on 02.11.2021.
//

#include "APDS_Sensor.h"
#include <Arduino_APDS9960.h>

void APDS_Sensor::APDS_Sensor() {

}

void APDS_Sensor::start() {
    if (APDS.begin()) {
        available = true;
    }
}

void APDS_Sensor::end() {
    APDS.end()
    available = false;
}

void APDS_Sensor::get_color(int& r, int& g, int& b) {
    if (!available) {
        return;
    }
    APDS.readColor(r, g, b);

}
int APDS_Sensor::get_light() {
    if (!available) {
        return;
    }
    int c;
    APDS.readColor(r, g, b, c);
    return c;
}

void APDS_Sensor::get_proximity() {
    if (!available) {
        return;
    }
    return APDS.readProximity();
}