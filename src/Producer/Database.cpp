//
// Created by tuhum on 18.03.2024.
//

#include "Database.h"

Database::Database() {
    connection = PQconnectdb(
            "dbname=mydb user=myuser password=33333333 host=localhost port=5432");
    if (PQstatus(connection) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(connection)
                  << std::endl;
        PQfinish(connection);
        connected = false;
    }
}

std::string Database::getFrom(const int &data) {
    std::string selectQuery = "SELECT datetime FROM control WHERE temp = ($1) ORDER BY datetime DESC LIMIT 1";
    std::string param = std::to_string(data);
    const char *paramValues[1] = {param.c_str()};
    const int paramLengths[1] = {static_cast<int>(param.length())};
    const int paramFormats[1] = {0};
    PGresult *res = PQexecParams(connection, selectQuery.c_str(), 1, nullptr,
                                 paramValues, paramLengths, paramFormats, 0);
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cerr << "Error select query " << PQerrorMessage(connection) << std::endl;
        PQclear(res);
        return "Can't found value " + param;
    } else {
        std::string timestampValue;
        if (PQntuples(res) > 0 && PQgetvalue(res, 0, 0) != nullptr) {
            timestampValue = PQgetvalue(res, 0, 0);
        } else {
            timestampValue = NOTHING_TO_GET;
        }
        PQclear(res);
        return timestampValue;
    }
}


std::string Database::postTo(const std::string &fieldName, int val) {
    std::string insertQuery = "INSERT INTO control (" + fieldName + ") VALUES ($1)";
    std::string stringValue = std::to_string(val);
    const char *paramValues[1] = {stringValue.c_str()};
    const int paramLengths[1] = {static_cast<int>(stringValue.length())};
    const int paramFormats[1] = {0};
    PGresult *res = PQexecParams(connection, insertQuery.c_str(), 1, nullptr, paramValues, paramLengths, paramFormats,
                                 0);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Error insert query " << PQerrorMessage(connection) << std::endl;
        PQclear(res);
        return POST_FAIL;
    } else {
        PQclear(res);
        return POST_COMPLETE;
    }
}

std::string Database::deleteBy(int val) {
    const std::string insertQuery = "DELETE FROM control WHERE temp = ($1)";
    std::string stringValue = std::to_string(val);
    const char *paramValues[1] = {stringValue.c_str()};
    const int paramLengths[1] = {static_cast<int>(stringValue.length())};
    const int paramFormats[1] = {0};
    PGresult *res = PQexecParams(connection, insertQuery.c_str(), 1, nullptr, paramValues, paramLengths, paramFormats,
                                 0);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "Error delete query " << PQerrorMessage(connection) << std::endl;
        PQclear(res);
        return DELETE_FAIL;
    } else {
        int rowsAffected = atoi(PQcmdTuples(res));
        PQclear(res);
        if (rowsAffected > 0) {
            return DELETE_COMPLETE;
        } else {
            return NOTHING_TO_DELETE;
        }
    }
}
