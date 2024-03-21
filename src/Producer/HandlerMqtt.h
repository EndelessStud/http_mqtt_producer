//
// Created by tuhum on 18.03.2024.
//

#ifndef PRODUCER_HANDLERMQTT_H
#define PRODUCER_HANDLERMQTT_H

#include "map"
#include "string"
#include "Database.h"
#include "Parser.h"

namespace configs {
    const std::string BROKER_ADDRESS = "tcp://mosquitto:1883";
    const std::string CLIENT_ID = "producer_client";
    const std::string GET_TOPIC_TO = "/get_response";
    const std::string POST_TOPIC_TO = "/post_response";
    const std::string DELETE_TOPIC_TO = "/delete_response";
    const std::string GET_TOPIC_FROM = "/get_requests";
    const std::string POST_TOPIC_FROM = "/post_requests";
    const std::string DELETE_TOPIC_FROM = "/delete_requests";
}

class HandlerMqtt {
public:
    HandlerMqtt() = default;

    HandlerMqtt(HandlerMqtt &other) = default;

    ~HandlerMqtt() = default;

    void add_route(const std::string &path,void (HandlerMqtt::*handler)(std::string &topic,std::string &data));

    void handle_msg(std::string &path, std::string &data);

    void handle_get_topic(std::string &topic,std::string &data);

    void handle_post_topic(std::string &topic,std::string &data);

    void handle_delete_topic(std::string &topic,std::string &data);

private:
    std::map<std::string, void (HandlerMqtt::*)(std::string &topic,std::string &data)> routes;
    Database db;
};


#endif //PRODUCER_HANDLERMQTT_H
