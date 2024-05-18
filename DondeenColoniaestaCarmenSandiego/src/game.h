#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game();
    ~Game();

    void start();
    void end();
    void saveProgress(const std::string &filename);
    void loadProgress(const std::string &filename);

private:
    void initialize();
    void cleanup();
    // Otros métodos y variables privadas
};

#endif // GAME_H