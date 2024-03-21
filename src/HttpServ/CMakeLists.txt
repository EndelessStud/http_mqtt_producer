cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp HttpServer.cpp HttpServer.h Handler.cpp Handler.h Router.cpp Router.h MQTT/MqttClient.cpp MQTT/MqttClient.h MQTT/MqttCallback.cpp MQTT/MqttCallback.h)
find_package(PahoMqttCpp REQUIRED)
find_package(Boost REQUIRED)


target_link_libraries(${PROJECT_NAME} PahoMqttCpp::paho-mqttpp3)

set(PAHO_WITH_SSL=TRUE)

install(TARGETS  ${PROJECT_NAME} DESTINATION bin)

