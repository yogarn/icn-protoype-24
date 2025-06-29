#include "phmeter_tds.h"

PHMeter::PHMeter(uint8_t analogPin, float offset)
    : _analogPin(analogPin), _offset(offset), _neutralVoltage(2.5), _acidVoltage(3.0) {}

void PHMeter::begin() {
    pinMode(_analogPin, INPUT);
}

float PHMeter::readPH() {
    int sensorValue = analogRead(_analogPin);
    float voltage = sensorValue * 5.0 / 1023.0;

    // Map voltage to pH (simple linear approximation between pH 4 and pH 7)
    float slope = (7.0 - 4.0) / (_neutralVoltage - _acidVoltage);
    float intercept = 7.0 - slope * _neutralVoltage;

    float ph = slope * voltage + intercept + _offset;
    return ph;
}

void PHMeter::calibrate(float voltage, float phValue) {
    // Optional: implement your own calibration logic here
    // For simplicity, you can adjust offset if needed
    float measuredPH = readPH();
    _offset = phValue - measuredPH;
}
