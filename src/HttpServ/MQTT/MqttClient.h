//
// Created by tuhum on 16.03.2024.
//

#ifndef UNTITLED_MQTTCLIENT_H
#define UNTITLED_MQTTCLIENT_H

#include "string"
#include "mqtt/async_client.h"
#include "MqttCallback.h"

class MqttClient{
public:
    MqttClient(const std::string& broker_address, const std::string& client_id)
            : mqtt_client(broker_address, client_id) {}

    void disconnect(const std::string& topic_name);

    void setup();

    void send_message(const std::string& topic, const std::string& message);

    bool is_connected();
    void subscribe_to(const std::string& topic_name);
    MqttCallback& get_callback();
private:
    mqtt::async_client mqtt_client;
    MqttCallback callback;
};


#endif //UNTITLED_MQTTCLIENT_H
