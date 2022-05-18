#include <iostream>
#include <thread>
#include <random>
#include <fstream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Load
{
private:
    bool status;

public:
    Load()
    {
        status = true;
    }
    string getTimeStr()
    {
        time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string s(20, ' ');
        strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return s;
    }

    int getKw()
    {
        int min = 29;
        int max = 43;
        // random [29-43]
        int s = random() % (max - min + 1) + 29;
        return s;
    }
    bool getStatus()
    {
        return status;
    }
    int changeStatus()
    {
        status = !status;
        return status;
    }
    void writeToDB()
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3308", "root", "VBYEGBGA");
        con->setSchema("ems");

        stmt = con->createStatement();

        string command = "INSERT INTO loadOne(power,status, createTime) VALUE(";
        //%d,1,'2022-05-12 17:32:10')
        command.append(to_string(this->getKw()));
        command.append(",");
        command.append(to_string(this->getStatus()));
        command.append(",");
        command.append(this->getTimeStr());
        command.append(")");
        cout << "command: " << command << endl;

        stmt->execute(command);
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
    }
};

int main(void)
{
    ofstream myfile;
    Load refrigerator;
    int i = 1;
    while (1)
    {
        cout << refrigerator.getTimeStr() << " " << refrigerator.getKw() << " " << boolalpha << refrigerator.getStatus() << endl;
        if (i % 10 == 0)
        {
            refrigerator.changeStatus();
            i = 1;
        }
        i++;
        myfile.open("example.txt", ios::app);
        myfile << refrigerator.getTimeStr() << " " << refrigerator.getKw() << " " << boolalpha << refrigerator.getStatus() << endl;
        myfile.close();
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    return 0;
}
