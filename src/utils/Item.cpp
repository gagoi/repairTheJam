#include "Item.hpp"


Item::Item(std::string const & name, std::string const & texture_path) : _name(name), _texturePath("./res/textures/items/" + texture_path)
{
    _sprite = sf::RectangleShape(sf::Vector2f(30, 30));
    _texture.loadFromFile(_texturePath);
    _texture.setSmooth(true);
    _sprite.setTexture(&_texture);
    _text.setString(_name);
    _text.setFillColor(sf::Color::Magenta);
    _font.loadFromFile("./res/fonts/Underdog.otf");
    _text.setFont(_font);
}

Item::~Item()
{
}

void Item::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_text);
    target.draw(_sprite);
}
