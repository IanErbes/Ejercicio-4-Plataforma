#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

// Variables
Texture texture_plataforma;
Sprite sprite_plataforma;

// Punto de entrada a la aplicación
int main() {
    // Cargamos la textura de la plataforma
    texture_plataforma.loadFromFile("plataforma.jpg");

    // Cargamos el material del sprite de la plataforma
    sprite_plataforma.setTexture(texture_plataforma);

    // Creamos la ventana
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Plataformas al estilo Mario Bros");

    // Escala en Y creciente para cada plataforma
    float escalasY[] = { -0.2f, -0.3f, -0.4f, -0.5f, -0.6f, -0.7f };

    // Ancho de las plataformas
    float escalaX = 0.7f;
    float ancho = 50.0f;
    float alto = 50.0f;

    // Loop principal
    while (App.isOpen()) {
        // Limpiamos la ventana
        App.clear();

        // Dibujamos la escena

        // Dibuja varias plataformas con escalas diferentes en Y y el mismo ancho
        for (int i = 0; i < 6; i++) {
            float escalaY = escalasY[i];
            sprite_plataforma.setScale(ancho / texture_plataforma.getSize().x, escalaY);
            sprite_plataforma.setPosition(i * 80.0f, 400.0f);
            App.draw(sprite_plataforma);
        }
        
        sprite_plataforma.setScale(escalaX, alto / texture_plataforma.getSize().y);
        sprite_plataforma.setPosition(500.0f, 220.0f);
        
        App.draw(sprite_plataforma);
        
        // Mostramos la ventana
        App.display();
    }

    return 0;
}
