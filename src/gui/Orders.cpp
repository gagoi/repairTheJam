#include "Orders.hpp"

Orders::Orders() : _bg(sf::Vector2f(400, 500))
{
    Order * order = new Order();
    BrokenItem * b1 = new BrokenItem("MonItem", "./res/textures/items/en_craft_1.png");
    BrokenItem * b2 = new BrokenItem("UnAutreItem", "./res/textures/items/en_craft_1.png");
    BrokenItem * b3 = new BrokenItem("EncoreUn", "./res/textures/items/en_craft_1.png");
    order->add(b1);
    order->add(b2);
    order->add(b3);
    _orders.push_back(order);
    _bg.setFillColor(sf::Color(128, 128, 128));
}

Orders::~Orders()
{
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