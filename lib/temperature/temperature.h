#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor {
public:
    TemperatureSensor(uint8_t pin);

    void begin();
    float readTemperature();

private:
    OneWire oneWire;
    DallasTemperature sensors;
};

#endif
