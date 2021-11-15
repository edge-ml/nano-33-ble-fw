#include "Ard_Sens_edge.h"

// Set DEBUG to true in order to enable debug print
#define DEBUG true

void setup() {

#if DEBUG
    Serial.begin(9600);
    while (!Serial);
    Sens.debug(Serial);
#endif

    Sens.begin();
}

void loop() {
    // Update and then sleep
    Sens.update(100);
}
