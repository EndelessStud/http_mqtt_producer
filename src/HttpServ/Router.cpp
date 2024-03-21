//
// Created by tuhum on 16.03.2024.
//

#include "Router.h"

void Router::add_route(const std::string &path,void (Handler::*handler)(http::request<http::string_body> &, http::response<http::string_body> &)) {
    routes[path] = handler;
}

void Router::handle_request(const std::string &path, http::request<http::string_body> &req,http::response<http::string_body> &res, Handler &handler) {
    if (routes.find(path) != routes.end()) {
        (handler.*routes[path])(req, res);
    } else {
        res.result(http::status::not_found);
        res.body() = "Not Found";
        res.prepare_payload();
    }
}
