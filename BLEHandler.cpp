//
// Created by Dylan Ray Roodt on 30.10.2021.
//

#include "BLEHandler.h"

#include "Arduino.h"
#include "ArduinoBLE.h"

#include "sensors/SensorTypes.h"

#include "Sensortec.h"

// Sensor Data channels
BLEService sensorService("34c2e3bb-34aa-11eb-adc1-0242ac120002"); 
auto sensorDataUuid = "34c2e3bc-34aa-11eb-adc1-0242ac120002";
auto sensorConfigUuid = "34c2e3bd-34aa-11eb-adc1-0242ac120002";
BLECharacteristic sensorDataCharacteristic(sensorDataUuid, (BLERead | BLENotify), sizeof(SensorDataPacket));
BLECharacteristic sensorConfigCharacteristic(sensorConfigUuid, BLEWrite, sizeof(SensorConfigurationPacket));

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

  // Sensor channel
  BLE.setAdvertisedService(sensorService);
  sensorService.addCharacteristic(sensorConfigCharacteristic);
  sensorService.addCharacteristic(sensorDataCharacteristic);
  BLE.addService(sensorService);
  sensorConfigCharacteristic.setEventHandler(BLEWritten, receivedSensorConfig);

  //
  BLE.advertise();
  return true;
}

void BLEHandler::end() {
    bleActive = false;
    BLE.end();
}

void BLEHandler::update() {
  BLE.poll();

  // This check doesn't work with more than one client at the same time
  if (sensorDataCharacteristic.subscribed()) {

    // Simulate a request for reading new sensor data
    uint8_t availableData = sensortec.availableSensorData(); // <- TODO: Die Funktion existiert noch nicht!
    while (availableData) {
      SensorDataPacket data;
      sensortec.readSensorData(data); // <- TODO: Die Funktion existiert noch nicht!
      sensorDataCharacteristic.writeValue(&data, sizeof(SensorDataPacket));
      --availableData;
    }

  }

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

void BLEHandler::debug(Stream &stream) {
    _debug = &stream;
    BLE.debug(stream);
}
