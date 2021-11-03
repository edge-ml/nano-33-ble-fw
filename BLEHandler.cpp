//
// Created by Dylan Ray Roodt on 30.10.2021.
//

#include "BLEHandler.h"

Stream* BLEHandler::_debug = NULL;

BLEHandler::BLEHandler() {

}

// Sensor channel
void BLEHandler::receivedSensorConfig(BLEDevice central, BLECharacteristic characteristic)
{
    SensorConfigurationPacket data;
    characteristic.readValue(&data, sizeof(data));
    if (_debug) {
        _debug->println("configuration received: ");
        _debug->print("data: ");
        _debug->println(data.sensorId);
        _debug->println(data.sampleRate);
        _debug->println(data.latency);
    }


    sensortec.configureSensor(data);
}

bool BLEHandler::begin() {
    if (!BLE.begin()) {
        return false;
    }
    bleActive = true;

    // Code for name
    String address = BLE.address();
    String name;
    int length;

    address.toUpperCase();
    length = address.length();

    name = "BLESense-";
    name += address[length - 5];
    name += address[length - 4];
    name += address[length - 2];
    name += address[length - 1];

    BLE.setLocalName(name.c_str());
    BLE.setDeviceName(name.c_str());

    if (_debug) {
        _debug->println("BLEHandler Begin: ");
        _debug->print("address = ");
        _debug->println(address);
        _debug->print("name = ");
        _debug->println(name);
    }

    // Other code for begin



    return true;
}

void BLEHandler::end() {
    bleActive = false;
    BLE.end();
}

void BLEHandler::update() {
    BLE.poll();


    // Other stuff check data available etc.
}

void BLEHandler::send(int *data) {
    // send list of int data as in int16 2 bytes each
    // first element is length of array
}

void BLEHandler::send(float *data) {
    // send list of float data floats 4 bytes each
    // first element is length of array (just convert to int)
}

void BLEHandler::poll(unsigned long timeout) {
    BLE.poll(timeout);
}

void BLEHandler::debug(int &stream) {
    _debug = &stream;
    BLE.debug(stream);
}