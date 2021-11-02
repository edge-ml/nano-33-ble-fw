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

private:
    bool available = false;
};


#endif //BARO_SENSOR_H
