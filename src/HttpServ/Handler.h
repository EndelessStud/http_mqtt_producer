//
// Created by tuhum on 16.03.2024.
//

#ifndef UNTITLED_HANDLER_H
#define UNTITLED_HANDLER_H

#include "boost/beast/http.hpp"
#include "MQTT/MqttClient.h"

namespace http = boost::beast::http;

namespace configs{
    const std::string BROKER_ADDRESS = "tcp://mosquitto:1883";
    const std::string CLIENT_ID = "http_to_mqtt_client";
    const std::string GET_TOPIC_FROM = "/get_response";
    const std::string POST_TOPIC_FROM = "/post_response";
    const std::string DELETE_TOPIC_FROM = "/delete_response";
    const std::string GET_TOPIC_TO = "/get_requests";
    const std::string POST_TOPIC_TO = "/post_requests";
    const std::string DELETE_TOPIC_TO = "/delete_requests";
    const unsigned short int HTTP_PORT = 8080;
}


class Handler {
public:
    Handler() = default;
    Handler(Handler &other) = default;
    ~Handler() = default;
      void handle_get(http::request<http::string_body>& req, http::response<http::string_body>& res);
      void handle_post(http::request<http::string_body>& req, http::response<http::string_body>& res);
      void handle_delete(http::request<http::string_body>& req, http::response<http::string_body>& res);
};


#endif //UNTITLED_HANDLER_H
