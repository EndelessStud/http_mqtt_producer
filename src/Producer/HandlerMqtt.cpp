//
// Created by tuhum on 18.03.2024.
//

#include "HandlerMqtt.h"

void HandlerMqtt::handle_get_topic(std::string &topic, std::string &data) {
    topic = configs::GET_TOPIC_TO;
    data = db.getFrom(Parser::getDataTemp(data));
}

void HandlerMqtt::handle_post_topic(std::string &topic, std::string &data) {
    topic = configs::POST_TOPIC_TO;
    data = db.postTo(Parser::getField(data), Parser::getDataTemp(data));
}

void HandlerMqtt::handle_delete_topic(std::string &topic, std::string &data) {
    topic = configs::DELETE_TOPIC_TO;
    data = db.deleteBy(Parser::getDataTemp(data));
}

void HandlerMqtt::add_route(const std::string &path, void (HandlerMqtt::*handler)(std::string &topic, std::string &)) {
    routes[path] = handler;
    std::cout << path << std::endl;
}

void HandlerMqtt::handle_msg(std::string &path, std::string &data) {
    if (routes.find(path) != routes.end()) {
        (*this.*routes[path])(path, data);
    } else {
        data = "Not Found route";
    }
}
