#include "Arduino.h"
#include "turbidty.h"

TurbiditySensor turbSensor(A1); // Turbidity sensor connected to analog pin A1

void setup() {
    Serial.begin(9600);
    turbSensor.begin();
}

void loop() {
    float ntu = turbSensor.readNTU();
    Serial.print("Turbidity (NTU): ");
    Serial.println(ntu);

    delay(1000); // Read every 1 second
}
