#include "Block.hpp"

Block::Block(int x, int y) : _sprite(sf::Vector2f(50, 50))
{
    _sprite.setFillColor(sf::Color::Cyan);
    _sprite.setPosition(400 + x * 50, y * 50);
}

Block::~Block()
{
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_sprite);
}

bool Block::contains(sf::Vector2f const & pos) const
{
    return _sprite.getGlobalBounds().contains(pos);
}
