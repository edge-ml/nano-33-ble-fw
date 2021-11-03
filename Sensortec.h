//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#include "sensors/SensorTypes.h"
#include "sensors/SensorID.h"
#include "sensors/SensorManager.h"
#include "BLEHandler.h"

#ifndef SENSORTEC_H
#define SENSORTEC_H

class Sensortec {
public:
    Sensortec();

    bool begin();
    void update();
    void configureSensor(SensorConfigurationPacket& config);

    // Add additional methods

    void debug(Stream &stream);

private:
    Sensor sensors[SENSOR_COUNT];
    int ID_type_assignment[SENSOR_COUNT];

    Stream *_debug;
    void init_ID_type_assignment();
    void update_sensor(Sensor sens);
    void send_sensor_data(int ID);
};

extern Sensortec sensortec;

#endif //SENSORTEC_H
