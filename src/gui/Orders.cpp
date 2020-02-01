#include "Orders.hpp"

Orders* Orders::instance = nullptr;

Orders::Orders() : _bg(sf::Vector2f(400, 500))
{
    Order * order = new Order();
    _orders.push_back(order);
    _bg.setFillColor(sf::Color(128, 128, 128));
}

Orders::~Orders()
{
    for (auto &&o : _orders)
    {
        delete o;
    }
    
}

void Orders::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_bg);
    for (auto&& order : _orders)
    {
        target.draw(*order);
    }
}


void Orders::mouseHandler(sf::Vector2f const & pos)
{
    for (auto &&order : _orders)
    {
        order->mouseHandler(pos);
    }
    
}