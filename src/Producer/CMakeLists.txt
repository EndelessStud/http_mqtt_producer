cmake_minimum_required(VERSION 3.20)
project(Producer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Producer main.cpp Database.cpp Database.h Parser.cpp Parser.h HandlerMqtt.cpp HandlerMqtt.h MqttClient.cpp MqttClient.h)

find_package(PahoMqttCpp REQUIRED)
find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 14)

target_link_libraries(${PROJECT_NAME} pq)
target_link_libraries(${PROJECT_NAME} PahoMqttCpp::paho-mqttpp3)

set(PAHO_WITH_SSL=TRUE)

install(TARGETS  ${PROJECT_NAME} DESTINATION bin)

