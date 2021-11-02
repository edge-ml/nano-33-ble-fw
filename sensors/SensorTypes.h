//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#ifndef SENSORTYPES_H
#define SENSORTYPES_H

struct __attribute__((packed)) SensorConfigurationPacket {
    uint8_t sensorId;
    // sample rate is used also to enable/disable the sensor
    // 0 for disable, else for enable
    float sampleRate;
    // latency indicates how much ms time a new value is retained in its fifo
    // before a notification to the host is sent via interrupt
    // expressed in 24 bit
    uint32_t latency;
};

#endif //SENSORTYPES_H
