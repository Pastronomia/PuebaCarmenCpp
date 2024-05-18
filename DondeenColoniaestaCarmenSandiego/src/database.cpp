#include "database.h"
#include <iostream>

Database::Database(const std::string& dbName) {
    int exit = sqlite3_open(dbName.c_str(), &DB);
    if (exit) {
        std::cerr << "Error al abrir la base de datos." << std::endl;
    }
}

Database::~Database() {
    sqlite3_close(DB);
}

void Database::createTable() {
    std::string sql = "CREATE TABLE IF NOT EXISTS JUGADORES("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NOMBRE TEXT NOT NULL, "
                      "CLAVE TEXT NOT NULL);";

    char* messageError;
    int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error al crear la tabla." << std::endl;
        sqlite3_free(messageError);
    } else {
        std::cout << "Tabla creada con éxito." << std::endl;
    }
}

void Database::registerPlayer(const std::string& nombre, const std::string& clave) {
    std::string sql = "INSERT INTO JUGADORES (NOMBRE, CLAVE) VALUES('" + nombre + "', '" + clave + "');";

    char* messageError;
    int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error al registrar el jugador." << std::endl;
        sqlite3_free(messageError);
    } else {
        std::cout << "Jugador registrado con éxito." << std::endl;
    }
}

bool Database::loginPlayer(const std::string& nombre, const std::string& clave) {
    std::string sql = "SELECT * FROM JUGADORES WHERE NOMBRE = '" + nombre + "' AND CLAVE = '" + clave + "';";
    sqlite3_stmt* stmt;

    int exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

    if (exit != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta." << std::endl;
        return false;
    }

    exit = sqlite3_step(stmt);

    if (exit == SQLITE_ROW) {
        std::cout << "Inicio de sesión exitoso." << std::endl;
        sqlite3_finalize(stmt);
        return true;
    } else {
        std::cout << "Nombre o clave incorrectos." << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }
}
