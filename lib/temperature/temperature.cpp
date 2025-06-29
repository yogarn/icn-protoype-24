#include "temperature.h"

TemperatureSensor::TemperatureSensor(uint8_t pin)
    : oneWire(pin), sensors(&oneWire) {}

void TemperatureSensor::begin() {
    sensors.begin();
}

float TemperatureSensor::readTemperature() {
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0); // Only one sensor assumed
}
