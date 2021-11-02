//
// Created by Dylan Ray Roodt on 02.11.2021.
//

#ifndef IMU_SENSOR_H
#define IMU_SENSOR_H

class IMU_Sensor {
public:
    IMU_Sensor();
    void start();
    void end();

    void get_acc(float& x, float& y, float& z);
    void get_gyro(float& x, float& y, float& z);
    void get_mag(float& x, float& y, float& z);

private:
    bool available = false;
};

#endif //IMU_SENSOR_H
