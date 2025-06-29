#include <EEPROM.h>
#include <Arduino.h>
#include "gravity_tds.h"
#include "ldr.h"
#include "ph_meter.h"
#include "temperature.h"
#include "turbidity.h"
#include "config.h"

// Pin definitions
#define TdsSensorPin A1
#define LDR_PIN A2
#define PH_PIN A0
#define TURBIDITY_PIN A3
#define TEMP_PIN 2

// Sensor objects
GravityTDS gravityTds;
LDR ldr(LDR_PIN, LDR_THRESHOLD, LDR_REFERENCE);
PHMeter phSensor(PH_PIN);
TemperatureSensor tempSensor(TEMP_PIN);
TurbiditySensor turbSensor(TURBIDITY_PIN);

// Variables
float temperature = 25, tdsValue = 0;
int ldrValue = 0;
int ldrVoltage = 0;
bool isLdrBright = false;
float phValue = 0;
float tempC = 0;
float ntu = 0;

void setup()
{
    Serial.begin(115200);
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(3.3);  // reference voltage on ADC
    gravityTds.setAdcRange(4096);  // 12bit ADC
    gravityTds.begin();
    phSensor.begin();
    tempSensor.begin();
    turbSensor.begin();
}

void loop()
{
    // Temperature
    tempC = tempSensor.readTemperature();
    temperature = tempC;

    // TDS
    gravityTds.setTemperature(temperature);
    gravityTds.update();
    tdsValue = gravityTds.getTdsValue();

    // LDR
    ldrValue = ldr.readRaw();
    ldrVoltage = ldr.readVoltage();
    isLdrBright = ldr.isBright();

    // pH
    phValue = phSensor.readPH();

    // Turbidity
    ntu = turbSensor.readNTU();

    // Print all sensor values
    Serial.print("Temperature (C): "); Serial.println(tempC);
    Serial.print("TDS (ppm): "); Serial.println(tdsValue, 0);
    Serial.print("LDR: "); Serial.print(ldrValue);
    Serial.print(" | V: "); Serial.print(ldrVoltage, 2);
    Serial.print(" | Bright: "); Serial.println(isLdrBright ? "Yes" : "No");
    Serial.print("pH: "); Serial.println(phValue);
    Serial.print("Turbidity (NTU): "); Serial.println(ntu);
    Serial.println("------------------------");
    delay(1000);
}
