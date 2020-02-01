#include "Block.hpp"

std::mt19937 Block::gen = std::mt19937(1924);
std::uniform_real_distribution<> Block::rand = std::uniform_real_distribution<>(0, 1); 

Block::Block(int x, int y) : _bg_sprite(sf::Vector2f(50, 50))
{
    _type = NORMAL;
    _item = nullptr;
    _bg.loadFromFile("./res/textures/world/workbench.png");
    _bg_sprite.setTexture(&_bg);
    _bg_sprite.setPosition(400 + x * 50, y * 50);
}

Block::Block(int x, int y, Type t) : Block(x, y)
{
    _fg_sprite.setSize(sf::Vector2f(50, 50));
    _type = t;
    switch (t)
    {
        case SCREWDRIVER :
            _fg.loadFromFile("./res/textures/world/screwdriver.png");
            break;
        case INPUT : 
            _bg.loadFromFile("./res/textures/world/input.png");
            _fg.loadFromFile("./res/textures/world/input.png");
            break;
    }
    _fg_sprite.setTexture(&_fg);
    _fg_sprite.setPosition(400 + x * 50, y * 50);
}

Block::~Block()
{
    delete _item;
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_bg_sprite);
    if (_item != nullptr)
        target.draw(_fg_sprite);
}

bool Block::contains(sf::Vector2f const & pos) const
{
    return _bg_sprite.getGlobalBounds().contains(pos);
}

void Block::update()
{
    float r;
    switch (_type)
    {
        case INPUT:
            r = rand(gen);
            if (_item == nullptr && r < 0.005)
            {
                _item = new BrokenItem("Un item de test", "item2.png");
                _fg_sprite = sf::RectangleShape(sf::Vector2f(50, 50));
                _fg.loadFromFile(_item->getTexturePath());
                _fg_sprite.setTexture(&_fg);
                _fg_sprite.setPosition(_bg_sprite.getPosition());
                Orders::insertOrder(_item);
            }
        break;
        default:
        break;
    }
}