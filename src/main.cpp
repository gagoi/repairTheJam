#include <SFML/Graphics.hpp>

#include "gui/Orders.hpp"
#include "gui/Recipes.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    Recipes recipes;
    Orders orders;

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

        window.clear();
        window.draw(orders);
        window.draw(recipes);
        window.display();
    }

    return 0;
}