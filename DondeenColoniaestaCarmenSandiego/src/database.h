#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    Database(const std::string& dbName);
    ~Database();
    void createTable();
    void registerPlayer(const std::string& nombre, const std::string& clave);
    bool loginPlayer(const std::string& nombre, const std::string& clave);

private:
    sqlite3* DB;
};

#endif // DATABASE_H
