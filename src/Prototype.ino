#include "Ard_Sens_edge.h"

// Help: https://arduino.github.io/ArduinoAI/BLESense-test-dashboard/

// Set DEBUG to true in order to enable debug print
#define DEBUG true

void setup() {
  delay(5000);
#if DEBUG
    Serial.begin(9600);
    while (!Serial);
    //Sens.debug(Serial); // This makes everything hang...
#endif

    Sens.begin();
}
int i = 0;
void loop() {
    // Update and then sleep
    Sens.update(100);
    if(i % 100 == 0) {
      Serial.println("alive");
    }
    i++;
}
