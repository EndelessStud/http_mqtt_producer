//
// Created by tuhum on 18.03.2024.
//

#ifndef PRODUCER_MQTTCLIENT_H
#define PRODUCER_MQTTCLIENT_H

#include "mqtt/async_client.h"
#include "HandlerMqtt.h"

class MqttClient : public virtual mqtt::callback {
public:
    MqttClient(const std::string& broker_address, const std::string& client_id)
            : client(broker_address, client_id),running(true) {}

    void connect();

    void subscribe_at(const std::string &topic,void (HandlerMqtt::*handler)(std::string &topic,std::string &data));

    void message_arrived(mqtt::const_message_ptr msg) override;

    void processMessages() ;

    void stop();

private:
    std::queue<std::pair<std::string, std::string>> messageQueue;
    std::mutex queueMutex;
    std::condition_variable queueCondition;
    bool running;
    HandlerMqtt handlerMqtt;
    mqtt::async_client client;
};


#endif //PRODUCER_MQTTCLIENT_H
