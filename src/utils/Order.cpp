#include "Order.hpp"

Order::Order()
{
}

Order::~Order()
{
}


void Order::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    for (auto&& item : _items)
    {
        target.draw(*item);
    }
}


void Order::mouseHandler(sf::Vector2f const & pos)
{
    for (auto&& item : _items)
    {
        item->checkClick(pos);
    }
}