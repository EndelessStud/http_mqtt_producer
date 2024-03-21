#include "MqttClient.h"

int main() {
    MqttClient client(configs::BROKER_ADDRESS,configs::CLIENT_ID);
    try {
    client.connect();
    client.subscribe_at(configs::GET_TOPIC_FROM,&HandlerMqtt::handle_get_topic);
    client.subscribe_at(configs::POST_TOPIC_FROM,&HandlerMqtt::handle_post_topic);
    client.subscribe_at(configs::DELETE_TOPIC_FROM,&HandlerMqtt::handle_delete_topic);
    client.processMessages();
    } catch (const mqtt::exception &exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
    }
    return 0;
}
