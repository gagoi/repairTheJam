#include "Block.hpp"

Block::Block(int x, int y) : _bg_sprite(sf::Vector2f(50, 50))
{
    _bg.loadFromFile("./res/textures/world/workbench.png");
    _bg_sprite.setTexture(&_bg);
    _bg_sprite.setPosition(400 + x * 50, y * 50);
}

Block::Block(int x, int y, Type t) : Block(x, y)
{
    _fg_sprite.setSize(sf::Vector2f(50, 50));
    _type = t;
    _fg.loadFromFile("./res/textures/world/screwdriver.png");
    _fg_sprite.setTexture(&_fg);
    _fg_sprite.setPosition(400 + x * 50, y * 50);
}

Block::~Block()
{
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_bg_sprite);
    target.draw(_fg_sprite);
}

bool Block::contains(sf::Vector2f const & pos) const
{
    return _bg_sprite.getGlobalBounds().contains(pos);
}