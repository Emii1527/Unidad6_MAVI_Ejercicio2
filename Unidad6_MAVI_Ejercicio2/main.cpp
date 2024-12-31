#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Unidad6_MAVI_Ejercicio2");
    sf::CircleShape circle(30.f);
    circle.setFillColor(sf::Color::Magenta);

    // Vectores para posici�n y velocidad
    sf::Vector2f position(400.f, 300.f);
    sf::Vector2f velocity(0.f, 0.f);

    // Aceleraci�n en x, y
    const sf::Vector2f acceleration(200.f, 200.f); // Aceleraci�n (x, y)
    const float deltaTime = 0.01f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controlar aceleraci�n con teclado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x += acceleration.x * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x -= acceleration.x * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            velocity.y += acceleration.y * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity.y -= acceleration.y * deltaTime;
        }

        // Limitar el c�rculo dentro de la pantalla
        if (position.x < 0) {
            position.x = 0;
            velocity.x = 0;
        }
        if (position.x + circle.getRadius() * 2 > window.getSize().x) {
            position.x = window.getSize().x - circle.getRadius() * 2;
            velocity.x = 0;
        }
        if (position.y < 0) {
            position.y = 0;
            velocity.y = 0;
        }
        if (position.y + circle.getRadius() * 2 > window.getSize().y) {
            position.y = window.getSize().y - circle.getRadius() * 2;
            velocity.y = 0;
        }

        // Actualizar posici�n
        position += velocity * deltaTime;

        // Dibujar
        circle.setPosition(position);
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}