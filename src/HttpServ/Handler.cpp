//
// Created by tuhum on 16.03.2024.
//

#include "Handler.h"


void Handler::handle_get(http::request<http::string_body> &req, http::response<http::string_body> &res) {
    MqttClient client(configs::BROKER_ADDRESS, configs::CLIENT_ID);
    client.setup();
    if (client.is_connected()) {
        MqttCallback &callback = client.get_callback();
        client.subscribe_to(configs::GET_TOPIC_FROM);
        client.send_message(configs::GET_TOPIC_TO, req.body());
        callback.set_response_string(res.body());
        std::unique_lock<std::mutex> lock(callback.mtx);
        callback.wait_for_response(lock);
        client.disconnect(configs::GET_TOPIC_TO);
    }
}

void Handler::handle_post(http::request<http::string_body> &req, http::response<http::string_body> &res) {
    MqttClient client(configs::BROKER_ADDRESS, configs::CLIENT_ID);
    client.setup();
    if (client.is_connected()) {
        MqttCallback &callback = client.get_callback();
        client.subscribe_to(configs::POST_TOPIC_FROM);
        client.send_message(configs::POST_TOPIC_TO, req.body());
        callback.set_response_string(res.body());
        std::unique_lock<std::mutex> lock(callback.mtx);
        callback.wait_for_response(lock);
        client.disconnect(configs::POST_TOPIC_TO);
    }
}

void Handler::handle_delete(http::request<http::string_body> &req, http::response<http::string_body> &res) {
    MqttClient client(configs::BROKER_ADDRESS, configs::CLIENT_ID);
    client.setup();
    if (client.is_connected()) {
        MqttCallback &callback = client.get_callback();
        client.subscribe_to(configs::DELETE_TOPIC_FROM);
        client.send_message(configs::DELETE_TOPIC_TO, req.body());
        callback.set_response_string(res.body());
        std::unique_lock<std::mutex> lock(callback.mtx);
        callback.wait_for_response(lock);
        client.disconnect(configs::DELETE_TOPIC_TO);
    }
}