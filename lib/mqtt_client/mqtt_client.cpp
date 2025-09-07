//
// Created by yogarn on 8/26/25.
//

#include "mqtt_client.h"

MqttClient::MqttClient(const char *server, int port, const char *clientId)
    : _server(server), _port(port), _clientId(clientId), _client(_wifiClient) {
}

void MqttClient::begin() {
    Serial.println("Starting MQTT client...");
    _client.setServer(_server, _port);
}

void MqttClient::setCallback(MQTT_CALLBACK_SIGNATURE) {
    _client.setCallback(callback);
}

void MqttClient::reconnect() {
    while (!_client.connected()) {
        Serial.print("[MQTT] Connecting...");
        if (_client.connect(_clientId)) {
            Serial.println("connected");
        } else {
            Serial.print("failed, rc=");
            Serial.print(_client.state());
            Serial.println(" retrying in 5s");
            delay(5000);
        }
    }
}

void MqttClient::loop() {
    if (!_client.connected()) {
        reconnect();
    }
    _client.loop();
}

bool MqttClient::publish(const char *topic, const char *payload) {
    return _client.publish(topic, payload);
}

bool MqttClient::subscribe(const char *topic) {
    return _client.subscribe(topic);
}
