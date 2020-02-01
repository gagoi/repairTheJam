#include "Player.hpp"

Player::Player() : _sprite(sf::Vector2f(50, 50))
{
    _sprite.setFillColor(sf::Color::Blue);
    _sprite.setOrigin(25, 25);
    _sprite.setPosition(400 + 50 * 2, 50 * 5);
}

Player::~Player()
{
}


void Player::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    sf::Vector2f p1;
    sf::Vector2f p2;
    target.draw(_sprite);

        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y -= 25 - 5;
        p2.y -= 25 - 5;
    sf::RectangleShape rect(sf::Vector2f(2, 2));
    rect.setPosition(p1);
    rect.setFillColor(sf::Color::Green);
    target.draw(rect);
}

void Player::update(std::vector<Block*> const & blocks)
{
    int speed = 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        while (checkCollide(UP, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        while (checkCollide(LEFT, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        while (checkCollide(DOWN, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(0, speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        while (checkCollide(RIGHT, blocks, speed) && speed != 0) speed /= 2;
            _sprite.move(speed, 0);
    }
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
        p1.y -= 25 + speed;
        p2.y -= 25 + speed;
        break;
    case LEFT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25 + speed;
        p2.x -= 25 + speed;
        p1.y -= 25;
        p2.y += 25;
        break;
    case DOWN:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x -= 25;
        p2.x += 25;
        p1.y += 25 + speed;
        p2.y += 25 + speed;
        break;
    case RIGHT:
        p1 = _sprite.getPosition();
        p2 = p1;
        p1.x += 25 + speed;
        p2.x += 25 + speed;
        p1.y -= 25;
        p2.y += 25;
        break;
    }

    return std::any_of(blocks.begin(), blocks.end(), [&](auto b){return b->contains(p1) || b->contains(p2);});
}