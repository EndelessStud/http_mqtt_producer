//
// Created by tuhum on 16.03.2024.
//

#ifndef UNTITLED_HTTPSERVER_H
#define UNTITLED_HTTPSERVER_H

#include "Router.h"


class HttpServer {
public:
    HttpServer() = default;
    HttpServer(HttpServer &other) = default;
    ~HttpServer() = default;
    void onStartServer();
private:
    Handler handle;
    Router router;
};


#endif //UNTITLED_HTTPSERVER_H
