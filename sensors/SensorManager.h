//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#ifndef TECO_NICLA_SENSORMANAGER_H
#define TECO_NICLA_SENSORMANAGER_H

class SensorManager {
public:
    SensorManager();

    // Add additional methods

    void debug(Stream &stream);

private:
    Stream *_debug;
};

extern SensorManager sensorManager;

#endif //TECO_NICLA_SENSORMANAGER_H
