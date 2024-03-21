//
// Created by tuhum on 18.03.2024.
//

#include "Parser.h"

int Parser::getDataTemp(const std::string& json) {

    boost::property_tree::ptree pt;
    std::istringstream ss(json);
    try {
        boost::property_tree::read_json(ss, pt);
        return pt.get<int>("temp");;
    } catch (const boost::property_tree::ptree_error& e) {
        std::cerr << "Ошибка при обработке JSON: " << e.what() << std::endl;
        return 0;
    }
}

std::string Parser::getField(const std::string &json) {
    boost::property_tree::ptree pt;
    std::istringstream ss(json);
    try {
        boost::property_tree::read_json(ss, pt);
        return pt.front().first;
    } catch (const boost::property_tree::ptree_error& e) {
        std::cerr << "Ошибка при обработке JSON: " << e.what() << std::endl;
    }
}
