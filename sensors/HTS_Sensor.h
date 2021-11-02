//
// Created by Dylan Ray Roodt on 02.11.2021.
//

#ifndef HTS_SENSOR_H
#define HTS_SENSOR_H


class HTS_Sensor {
    APDS_Sensor();
    void start();
    void end();

    float get_temperature();
    float get_humidity();
private:
    bool available = false;
};


#endif //HTS_SENSOR_H
