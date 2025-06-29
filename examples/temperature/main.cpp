#include "Arduino.h"
#include "temperature.h"

TemperatureSensor tempSensor(2); 

void setup() {
    Serial.begin(9600);
    tempSensor.begin();
}

void loop() {
    float tempC = tempSensor.readTemperature();
    Serial.print("Temperature (°C): ");
    Serial.println(tempC);

    delay(1000); // Read every 1 second
}
