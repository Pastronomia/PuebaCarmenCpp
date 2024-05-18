#include <SFML/Graphics.hpp>
#include <iostream>

void mostrarImagen() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plaza de Toros");

    sf::Texture texture;
    if (!texture.loadFromFile("https://www.colonia.gub.uy/plazadetoros/imgs/galeriaDeImagenes/inauguracion/img/10.jpg")) {
        std::cerr << "Error al cargar la imagen" << std::endl;
        return;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

int main() {
    // Llama a la función para mostrar la imagen
    mostrarImagen();

    return 0;
}
