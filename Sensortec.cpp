//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#include "Sensortec.h"

Sensortec::Sensortec() {

}

bool Sensortec::begin() {
    // Removed because Bosch sensors
    // Possibly init Arduino sensors
    return True;
}

void Sensortec::update() {
    // Do update possibly in SensorManager or have logic that handles which sensors are active or not
}

void BoschSensortec::configureSensor(SensorConfigurationPacket& config) {
    // Configure sensor in SensorManager

    // Set sensor here to active?
}

void Sensortec::debug(Stream &stream) {
    _debug = &stream;
}
