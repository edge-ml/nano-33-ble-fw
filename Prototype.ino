#include "Ard_Sens_edge.h"

// Help: https://arduino.github.io/ArduinoAI/BLESense-test-dashboard/

// Set DEBUG to true in order to enable debug print
#define DEBUG false

void setup() {
#if DEBUG
    Serial.begin(115200);
    Sens.debug(Serial);
#endif

    Sens.begin();
}

void loop() {
    // Update and then sleep
    Sens.update(100);
}
