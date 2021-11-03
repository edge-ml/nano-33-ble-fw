//
// Created by Dylan Ray Roodt on 30.10.2021.
//

#ifndef BLEHANDLER_H
#define BLEHANDLER_H

#include "Arduino.h"
#include "ArduinoBLE.h"

class BLEHandler {
public:
    BLEHandler();
    bool begin();
    void update();

    void send(int *data);
    void send(float *data);

    void poll(unsigned long timeout);
    void end();

    static void debug(Stream &stream);

    bool bleActive = false;

private:
    static Stream *_debug;
    static void receivedSensorConfig(BLEDevice central, BLECharacteristic characteristic);
};

extern BLEHandler bleHandler;

#endif //BLEHANDLER_H
