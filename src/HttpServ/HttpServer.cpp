//
// Created by tuhum on 16.03.2024.
//

#include "HttpServer.h"

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;

void HttpServer::onStartServer() {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(),configs::HTTP_PORT));
    router.add_route("GET", &Handler::handle_get);
    router.add_route("POST", &Handler::handle_post);
    router.add_route("DELETE", &Handler::handle_delete);
    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        boost::beast::flat_buffer buffer;
        http::request<http::string_body> request;
        http::read(socket, buffer, request);
        http::response<http::string_body> response{http::status::ok, request.version()};
        try {
           router.handle_request( request.method_string().to_string() , request, response, handle);
        } catch (mqtt::exception &e) {
            std::cerr << e.what() << std::endl;
            response.result(http::status::bad_gateway);
            response.version(request.version());
        } catch (std::runtime_error &e){
            std::cerr << e.what() << std::endl;
            response.result(http::status::gateway_timeout);
            response.version(request.version());
        }
        http::write(socket, response);
    }
}

