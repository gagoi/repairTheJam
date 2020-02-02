#include "Player.hpp"

Player::Player() : _sprite(sf::Vector2f(50, 100))
{
    _item = nullptr;
    _texture.loadFromFile("./res/textures/character.png");
    _sprite.setTextureRect(sf::IntRect(48 + 12, 19, 25, 45));
    _sprite.setTexture(&_texture);
    _sprite.setOrigin(25, 50);
    _sprite.setPosition(400 + 50 * 2, 50 * 5);
    _cpt = 0;
    _timeout = false;
}

Player::~Player()
{
}


void Player::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_sprite);
}

void Player::update(std::vector<Block*> const & blocks)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        int speed = 5;
        while (checkCollide(UP, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(0, -speed);
        changeTexture(UP);
        _side = UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        int speed = 5;
        while (checkCollide(LEFT, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(-speed, 0);
        changeTexture(LEFT);
        _side = LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        int speed = 5;
        while (checkCollide(DOWN, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(0, speed);
        changeTexture(DOWN);
        _side = DOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        int speed = 5;
        while (checkCollide(RIGHT, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(speed, 0);
        changeTexture(RIGHT);
        _side = RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !_timeout)
    {
        _timeout = true;
        if (_item == nullptr)
        {
            Block * b = checkPeakUp(_side, blocks, 30);
            if (b != nullptr) 
            {
                _item = b->getItem();
                b->removeItem();
            }
        } else
        {
            Block * b = checkDrop(_side, blocks, 30);
            if (b != nullptr) 
            {
                b->setItem(_item);
                _item = nullptr;
            }
        }
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _timeout)
    {
        _timeout = false;
    }
}

void Player::changeTexture(Side s)
{
    _sprite.setTextureRect(sf::IntRect(48 * (_cpt++ / 20) + 12 , 19 * (s + 1) + 45 * s , 25, 45));
    if (_cpt >= 20*4) _cpt = 0;
}


Block* Player::checkDrop(Side s, std::vector<Block*> const & blocks, int speed) const 
{
    sf::Vector2f p1;
    sf::Vector2f p2;
    switch (s)
    {
    case UP:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y -= speed;
        p2.y -= speed;
        break;
    case LEFT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25 + speed;
        p2.x -= 25 + speed;
        p1.y -= 0;
        p2.y += 25;
        break;
    case DOWN:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y += 50 + speed;
        p2.y += 50 + speed;
        break;
    case RIGHT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x += 25 + speed;
        p2.x += 25 + speed;
        p1.y -= 0;
        p2.y += 25;
        break;
    }
    for (auto &&b : blocks)
        if (b->getType() != DECOMPOSER_OUTPUT && b->getItem() == nullptr && (b->contains(p1) || b->contains(p2)))
            return b;
    
    return nullptr;
}

Block* Player::checkPeakUp(Side s, std::vector<Block*> const & blocks, int speed) const 
{
    sf::Vector2f p1;
    sf::Vector2f p2;
    switch (s)
    {
    case UP:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y -= speed;
        p2.y -= speed;
        break;
    case LEFT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25 + speed;
        p2.x -= 25 + speed;
        p1.y -= 0;
        p2.y += 25;
        break;
    case DOWN:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y += 50 + speed;
        p2.y += 50 + speed;
        break;
    case RIGHT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x += 25 + speed;
        p2.x += 25 + speed;
        p1.y -= 0;
        p2.y += 25;
        break;
    }
    for (auto &&b : blocks)
        if (b->getItem() != nullptr && (b->contains(p1) || b->contains(p2)))
            return b;
    
    return nullptr;
}

bool Player::checkCollide(Side s, std::vector<Block*> const & blocks, int speed) const
{
    sf::Vector2f p1;
    sf::Vector2f p2;
    switch (s)
    {
    case UP:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y -= speed;
        p2.y -= speed;
        break;
    case LEFT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25 + speed;
        p2.x -= 25 + speed;
        p1.y -= 0;
        p2.y += 50;
        break;
    case DOWN:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y += 50 + speed;
        p2.y += 50 + speed;
        break;
    case RIGHT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x += 25 + speed;
        p2.x += 25 + speed;
        p1.y -= 0;
        p2.y += 50;
        break;
    }

    return std::any_of(blocks.begin(), blocks.end(), [&](auto b){return b->contains(p1) || b->contains(p2);});
}