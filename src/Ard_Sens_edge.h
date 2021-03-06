//
// Created by Dylan Ray Roodt on 30.10.2021.
//

#ifndef ARD_SENS_EDGE_H
#define ARD_SENS_EDGE_H

#include "BLEHandler.h"
#include "Sensortec.h"

class Ard_Sense_edge {
public:
    Ard_Sense_edge();
    bool begin();
    void update(); // remove this to enforce a sleep
    void update(unsigned long ms); // Update and then sleep
    void delay(unsigned long ms);

    void debug(Stream &stream);
private:
    Stream *_debug;
};



extern Ard_Sense_edge Sens;

#endif //ARD_SENS_EDGE_H
