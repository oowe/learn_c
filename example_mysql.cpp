// run code g++ example_mysql.cpp -o example_mysql  -l mysqlcppconn && "/home/user/project/learn_cpp/"example_mysql

#include <iostream>
#include <stdlib.h>
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main()
{
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3308", "root", "password");
    con->setSchema("ems");

    stmt = con->createStatement();
    stmt->execute("INSERT INTO loadOne(power,status, createTime) VALUE(29,1,'2022-05-12 17:32:10')");
    //       execute 是用於無回傳值的情況，executeQuery則是有回傳值的情況使用

    res = stmt->executeQuery("SELECT * from loadOne");

    while (res->next())
    {
        cout << "index = " << res->getInt("index") << "\n";
        cout << "power = " << res->getInt("power") << "\n";
        cout << "status = " << res->getInt("status") << "\n";
        cout << "createTime = " << res->getString("createTime") << "\n";
        cout << endl;
    }
    delete res;
    delete stmt;
    delete con;
    //      res.getInt和res.getString的參數也可以接收正整數，代表第幾個column

    return 0;
}