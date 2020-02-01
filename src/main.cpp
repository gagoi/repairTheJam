#include <SFML/Graphics.hpp>

#include "gui/Orders.hpp"
#include "gui/Recipes.hpp"
#include "MainGame.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(60);
    Recipes recipes;
    Orders orders;
    MainGame game;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                orders.mouseHandler(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }
        }

        game.update();

        window.clear();
        window.draw(orders);
        window.draw(recipes);
        window.draw(game);
        window.display();
    }

    return 0;
}