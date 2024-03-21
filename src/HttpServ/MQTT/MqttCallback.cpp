//
// Created by tuhum on 18.03.2024.
//

#include "MqttCallback.h"

void MqttCallback::message_arrived(mqtt::const_message_ptr msg) {
    *response_str = msg->get_payload_str();
    this->notify_main_thread();
}

void MqttCallback::set_response_string(std::string &response) {
    response_str = &response;
}

void MqttCallback::wait_for_response(std::unique_lock<std::mutex> &lock) {
    if(cv.wait_for(lock,std::chrono::seconds(10)) == std::cv_status::timeout){
        throw std::runtime_error("Timeout error");
    }
}
