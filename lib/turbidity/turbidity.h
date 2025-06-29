#ifndef TURBIDITYSENSOR_H
#define TURBIDITYSENSOR_H

#include "Arduino.h"

class TurbiditySensor {
public:
    TurbiditySensor(uint8_t analogPin);

    void begin();
    float readNTU(); // Nephelometric Turbidity Units

private:
    uint8_t _analogPin;
};

#endif
