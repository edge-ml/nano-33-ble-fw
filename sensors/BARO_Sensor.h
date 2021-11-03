//
// Created by Dylan Ray Roodt on 02.11.2021.
//

#ifndef BARO_SENSOR_H
#define BARO_SENSOR_H


class BARO_Sensor {
public:
    BARO_Sensor();
    void start();
    void end();

    float get_pressure();

    const int sensor_count = 1;
private:
    bool available = false;
};

extern BARO_Sensor baro_sensor;

#endif //BARO_SENSOR_H
