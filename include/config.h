/**
 * @brief Configuration file
 */

#pragma once

// pin map
#define LDR_PIN 35
#define TDS_PIN 34

// hardware constants
#define TDS_AREF 3.3  // reference voltage on ADC, default 3.3V on ESP32
#define TDS_ADC_RANGE 4096  // 4096 for 12-bit ADC
#define LDR_REFERENCE 5.0

// environmental constants
#define TDS_TEMPERATURE 25  /**< default temperature for TDS calculations */
#define LDR_THRESHOLD 5

// mqtt config
#define MQTT_HOST "10.34.238.226"
#define MQTT_PORT 1883
#define MQTT_CLIENT "esp1"

// wifi config
#define WIFI_SSID "Lab-ICN_v3"
#define WIFI_PASS "labjarkomnomorsatu"
