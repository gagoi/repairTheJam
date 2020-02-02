#include "OrderItem.hpp"

OrderItem::OrderItem(Item * item, int row) : _bg(sf::Vector2f(WIDTH, 40)), _icon(sf::Vector2f(30, 30))
{
    _bg.setPosition(25, row * HEIGHT);
    _bg.setFillColor(sf::Color(200, 200, 200));
    _label.setString(item->getName());
    _label.setFont(item->getFont());
    _label.setFillColor(sf::Color::Red);
    _label.setPosition(65, row * HEIGHT);
    _texture.loadFromFile(item->getTexturePath());
    _icon.setTexture(&_texture);
    _icon.setPosition(30, row * HEIGHT + 5);
    _item = item->getName();
}

OrderItem::~OrderItem()
{
}

void OrderItem::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_bg);
    target.draw(_icon);
    target.draw(_label);
}

void OrderItem::checkClick(sf::Vector2f const & pos)
{
    if (_bg.getGlobalBounds().contains(pos))
    {
        //_selected = true;
        _bg.setFillColor(sf::Color::Green);
    }
    else 
    {
       // _selected = false;
       _bg.setFillColor(sf::Color::Red);
    }
}
