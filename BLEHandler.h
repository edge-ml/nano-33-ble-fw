//
// Created by Dylan Ray Roodt on 30.10.2021.
//

#ifndef TECO_NICLA_BLEHANDLER_H
#define TECO_NICLA_BLEHANDLER_H

#include "Arduino.h"
#include "ArduinoBLE.h"

class BLEHandler {
public:
    BLEHandler();
    bool begin();
    void update();

    void poll(unsigned long timeout);
    void end();

    static void debug(Stream &stream);

    bool bleActive = false;

private:
    static Stream *_debug;
    static void receivedSensorConfig(BLEDevice central, BLECharacteristic characteristic);
};

extern BLEHandler bleHandler;

#endif //TECO_NICLA_BLEHANDLER_H
