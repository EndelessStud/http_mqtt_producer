//
// Created by tuhum on 18.03.2024.
//

#ifndef UNTITLED_MQTTCALLBACK_H
#define UNTITLED_MQTTCALLBACK_H

#include "mqtt/callback.h"
#include "mutex"
#include "condition_variable"


class MqttCallback: public virtual mqtt::callback {
public:
    void message_arrived(mqtt::const_message_ptr msg) override;

    void set_response_string(std::string& response);

    inline void notify_main_thread() { cv.notify_one(); }

    void wait_for_response(std::unique_lock<std::mutex>& lock);

    std::mutex mtx;

private:
    std::string* response_str;
    std::condition_variable cv;
};


#endif //UNTITLED_MQTTCALLBACK_H
