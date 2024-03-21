//
// Created by tuhum on 16.03.2024.
//

#ifndef UNTITLED_ROUTER_H
#define UNTITLED_ROUTER_H

#include "map"
#include <boost/beast/core.hpp>
#include <boost/asio.hpp>
#include "Handler.h"

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

class Router {

public:
    std::map<std::string, void(Handler::*)(http::request<http::string_body>&, http::response<http::string_body>&)> routes;

    void add_route(const std::string& path, void(Handler::*handler)(http::request<http::string_body>&, http::response<http::string_body>&)) ;

    void handle_request(const std::string& path, http::request<http::string_body>& req, http::response<http::string_body>& res,Handler& handler);
};


#endif //UNTITLED_ROUTER_H
