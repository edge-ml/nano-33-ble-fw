//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#include "Sensortec.h"

Sensortec::Sensortec() {
    init_ID_type_assignment();
}

bool Sensortec::begin() {
    Sensor sens;
    for (int i=0; i<SENSOR_COUNT; i++) {
        sens = sensors[i];

        sens.ID = ID;
        sens.state = false;
        sens.active = false;
        sens.delay = 0;
        sens.last = -1;
    }
    return true;
}

void Sensortec::update() {
    for (int i=0; i<SENSOR_COUNT; i++) {
        sens = sensors[i];
        if (sens.state) {
            update_sensor(sens);
        } else if (sens.active) {
            sensorManager.end_sensor(ID);
            sens.active = false;
        }
    }
}

void Sensortec::configureSensor(SensorConfigurationPacket& config) {
    // Configure sensor in SensorManager

    // Set sensor here to active?
}

void Sensortec::update_sensor(Sensor sens) {
    if (!sens.active) {
        sensorManager.start_sensor(ID);
        sens.active = true;
    }

    unsigned long now = millis();
    if (now - sens.last > sens.delay) {
        sens.delay = now;
        send_sensor_data(sens.ID);
    }
}

void Sensortec::send_sensor_data(int ID) {
    // Get data from SensorManager
    // Send data via BLE
    int type = ID_type_assignment[ID];

    int *int_data;
    int *float_data;

    if (type == TYPE_INT) {
        int_data = sensorManager.get_int_data(ID);
        bleHandler.send(int_data);
    } else if (tpye == TYPE_FLOAT) {
        float_data = sensorManager.get_float_data(ID);
        bleHandler.send(float_data);
    }
}

void Sensortec::init_ID_type_assignment() {
    int ID;
    for (int i=0; i < INT_TYPE_COUNT; i++) {
        ID = RETURN_TYPE_INT[i];
        ID_type_assignment[ID] = TYPE_INT;
    }

    for (int i=0; i < FLOAT_TYPE_COUNT; i++) {
        ID = RETURN_TYPE_FLOAT[i];
        ID_type_assignment[ID] = TYPE_FLOAT;
    }
}

void Sensortec::debug(Stream &stream) {
    _debug = &stream;
}
