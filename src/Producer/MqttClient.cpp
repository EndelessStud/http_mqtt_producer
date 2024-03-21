//
// Created by tuhum on 18.03.2024.
//

#include "MqttClient.h"

void MqttClient::connect() {
    client.set_callback(*this);
    mqtt::connect_options options;
    options.set_keep_alive_interval(20);
    client.connect(options)->wait();
}

void MqttClient::message_arrived(mqtt::const_message_ptr msg) {
    std::unique_lock<std::mutex> lock(queueMutex);
    messageQueue.push({msg->get_topic(), msg->get_payload_str()});
    queueCondition.notify_one();
}

void MqttClient::processMessages() {
        while (running) {
            std::unique_lock<std::mutex> lock(queueMutex);
            queueCondition.wait(lock, [this] { return !messageQueue.empty() || !running; });
            if (!messageQueue.empty()) {
                auto message = messageQueue.front();
                messageQueue.pop();
                lock.unlock();
                handlerMqtt.handle_msg(message.first, message.second);
//                std::cout << message.first << "      " << message.second << std::endl;
                client.publish(message.first,message.second);
            }
        }
}

void MqttClient::stop() {
        running = false;
        queueCondition.notify_one();
}

void MqttClient::subscribe_at(const std::string &topic, void (HandlerMqtt::*handler)(std::string &,std::string &)) {
    handlerMqtt.add_route(topic,handler);
    client.subscribe(topic, 0)->wait();
}

