#ifndef GENERAL_DAO_HPP
#define GENERAL_DAO_HPP

#include <string>
#include <vector>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class GeneralDao
{
private:
    std::string host;
    std::string user;
    std::string pass;
    std::string database;

public:
    GeneralDao();
    GeneralDao(std::string host, std::string user, std::string pass, std::string database);
    ~GeneralDao();
    bool executeQuery(std::string statement, std::unique_ptr<sql::ResultSet> &res);
};

#endif