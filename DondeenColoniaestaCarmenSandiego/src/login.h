#ifndef LOGIN_H
#define LOGIN_H

#include "database.h"
#include <string>

class Login {
public:
    Login(Database& db);
    void showLoginScreen();

private:
    Database& db;
};

#endif // LOGIN_H
