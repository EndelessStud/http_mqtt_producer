//
// Created by tuhum on 16.03.2024.
//

#include "MqttClient.h"


void MqttClient::disconnect(const std::string &topic_name) {
    mqtt_client.unsubscribe(topic_name);
    mqtt_client.disconnect()->wait();
}

void MqttClient::send_message(const std::string &topic, const std::string &message) {
    mqtt::message_ptr pub_msg = mqtt::make_message(topic, message);
    mqtt_client.publish(pub_msg)->wait();
}

bool MqttClient::is_connected() {
    return mqtt_client.is_connected();
}

void MqttClient::setup() {
    mqtt_client.set_callback(callback);
    mqtt::connect_options options;
    options.set_keep_alive_interval(20);
    mqtt_client.connect(options)->wait();
}

MqttCallback &MqttClient::get_callback() {
    return callback;
}

void MqttClient::subscribe_to(const std::string &topic_name) {
    mqtt_client.subscribe(topic_name, 0)->wait();
}

