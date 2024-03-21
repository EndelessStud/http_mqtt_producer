//
// Created by tuhum on 18.03.2024.
//

#ifndef PRODUCER_DATABASE_H
#define PRODUCER_DATABASE_H

#include <postgresql/libpq-fe.h>
#include "iostream"


class Database {
public:
    Database();

    bool connected = true;

    std::string getFrom(const int &data);

    std::string postTo(const std::string &fieldName, int value);

    std::string deleteBy(int value);

private:
    PGconn *connection;
    const std::string POST_COMPLETE = "POSTED SUCCESSFULLY";
    const std::string POST_FAIL = "POST FAIL";
    const std::string DELETE_COMPLETE = "DELETED SUCCESSFULLY";
    const std::string DELETE_FAIL = "DELETE FAIL";
    const std::string NOTHING_TO_DELETE = "DELETE FAIL";
    const std::string NOTHING_TO_GET = "NULL SELECTED DATA";
};


#endif //PRODUCER_DATABASE_H
