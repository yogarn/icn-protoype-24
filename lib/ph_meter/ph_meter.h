#ifndef PHMETER_H
#define PHMETER_H

#include "Arduino.h"

class PHMeter {
public:
    PHMeter(uint8_t analogPin, float offset = 0.0);

    void begin();
    float readPH();
    void calibrate(float voltage, float phValue);

private:
    uint8_t _analogPin;
    float _offset;
    float _neutralVoltage;  // Voltage at pH 7
    float _acidVoltage;     // Voltage at pH 4
};

#endif
