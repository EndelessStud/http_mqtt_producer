//
// Created by tuhum on 18.03.2024.
//

#ifndef PRODUCER_PARSER_H
#define PRODUCER_PARSER_H
#include "string"
#include "iostream"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

class Parser {
public:
    Parser() = default;
    Parser(Parser &other) = default;
    ~Parser() = default;
    static int getDataTemp(const std::string& json);
    static std::string getField(const std::string& json);
};


#endif //PRODUCER_PARSER_H
