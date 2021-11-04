//
// Created by Dylan Ray Roodt on 02.11.2021.
//

#ifndef HTS_SENSOR_H
#define HTS_SENSOR_H


class HTS_Sensor {
    HTS_Sensor();
    void start();
    void end();

    float get_temperature();
    float get_humidity();

    const int sensor_count = 2;
private:
    bool available = false;
};

extern HTS_Sensor hts_sensor;

#endif //HTS_SENSOR_H
