//
// Created by Dylan Ray Roodt on 30.10.2021.
//

/*
Sensors:
 - APDS
 - HTS
 - BARO
 - IMU
 - PDM

 - arm_rfft

 (Set Onbord LED)

 APDS:
 - Read colour
 - Proximity
 - Gesture (?)

 HTS:
 - Temperature
 - Humidity

 BARO:
 - Pressure

 IMU:
 - Acceleration
 - Gyroscope
 - MagneticField

 PDM:
 - Microphone

 arm_rfft:
 - Microphone
 */

#ifndef SENSORID_H
#define SENSORID_H

const int IMU_ACCELERATION = 0;
const int IMU_GYROSCOPE = 1;
const int IMU_MAGNET = 2;

const int HTS_TEMP = 3;
const int HTS_HUM = 4;

const int BARO_PRESS = 5;

const int APDS_COLOUR = 6;
const int APDS_PROX = 7;
const int ADPS_GEST = 8;



const int SENSOR_COUNT = 9;

#endif //SENSORID_H
