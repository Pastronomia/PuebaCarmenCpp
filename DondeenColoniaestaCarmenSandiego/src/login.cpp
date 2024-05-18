#include "login.h"
#include <iostream>

Login::Login(Database& db) : db(db) {}

void Login::showLoginScreen() {
    std::string nombre, clave;
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese su clave: ";
    std::cin >> clave;

    if (!db.loginPlayer(nombre, clave)) {
        std::cout << "¿Desea registrarse? (s/n): ";
        char opcion;
        std::cin >> opcion;

        if (opcion == 's') {
            db.registerPlayer(nombre, clave);
        }
    }
}