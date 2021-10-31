//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#ifndef TECO_NICLA_SENSORTEC_H
#define TECO_NICLA_SENSORTEC_H

class Sensortec {
public:
    Sensortec();

    bool begin();
    void update();
    void configureSensor(SensorConfigurationPacket& config);

    // Add additional methods

    void debug(Stream &stream);

private:

    Stream *_debug;
};

extern Sensortec sensortec;

#endif //TECO_NICLA_SENSORTEC_H