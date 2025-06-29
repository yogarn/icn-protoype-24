#include "ph_meter.h"

PHMeter phSensor(A0);

void setup() {
    Serial.begin(9600);
    phSensor.begin();
}

void loop() {
    float phValue = phSensor.readPH();
    Serial.print("pH: ");
    Serial.println(phValue);
    delay(1000);
}
