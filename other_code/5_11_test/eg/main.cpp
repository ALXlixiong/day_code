#include <iostream>
#include "MyDb.h"

int main() {
    MyDb db;

    string host = "47.103.3.230";
    string user = "root";
    string passwd = "password";
    string dbName = "oj_model";
    int port = 3306;

    cout<<"start\n";

    //连接数据库
    bool conn = db.initDB(host, user, passwd, dbName, port);

    if (!conn) {
        cout<<"connect fails\n";
    }

    cout<<"ok" <<endl;

//    //将用户信息添加到数据库
//    string sql = "INSERT account values('1', 'fengxin');";
//    sql = "INSERT account values('2', 'axin');";
//    //将所有用户信息读出，并输出。
    std::string sql = "set names utf8";
    db.exeSQL(sql);
    sql = "SELECT * from question;";
    db.exeSQL(sql);

    return 0;
}

