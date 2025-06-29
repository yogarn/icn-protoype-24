#include "turbidity.h"

TurbiditySensor::TurbiditySensor(uint8_t analogPin)
    : _analogPin(analogPin) {}

void TurbiditySensor::begin() {
    pinMode(_analogPin, INPUT);
}

float TurbiditySensor::readNTU() {
    int value = analogRead(_analogPin);
    float voltage = value * (5.0 / 1023.0);

    // Empirical formula from SEN0189 datasheet
    float ntu = -1120.4 * voltage * voltage + 5742.3 * voltage - 4352.9;
    return ntu;
}
