#include "MainGame.hpp"

MainGame::MainGame() : _bg(sf::Vector2f(1500, 1000))
{
    _blocks.push_back(new Block(0, 0));
    _blocks.push_back(new Block(1, 0));
    _blocks.push_back(new Block(2, 0));
    _blocks.push_back(new Block(3, 0));
    _blocks.push_back(new Block(4, 0));
    _blocks.push_back(new Block(5, 0, Block::SCREWDRIVER));
    _blocks.push_back(new Block(6, 0));
    _blocks.push_back(new Block(7, 0));
    _blocks.push_back(new Block(8, 0));
    _blocks.push_back(new Block(9, 0));

    _blocks.push_back(new Block(0, 1));
    _blocks.push_back(new Block(0, 2));
    _blocks.push_back(new Block(0, 3));
    _blocks.push_back(new Block(0, 4));
    _blocks.push_back(new Block(0, 5));
    _blocks.push_back(new Block(0, 6));
    _blocks.push_back(new Block(0, 7));
    _blocks.push_back(new Block(0, 8));
    _blocks.push_back(new Block(0, 9));

    _blocks.push_back(new Block(0, 10));
    _blocks.push_back(new Block(1, 10));
    _blocks.push_back(new Block(2, 10));
    _blocks.push_back(new Block(3, 10));
    _blocks.push_back(new Block(4, 10));
    _blocks.push_back(new Block(5, 10));
    _blocks.push_back(new Block(6, 10));
    _blocks.push_back(new Block(7, 10));
    _blocks.push_back(new Block(8, 10));
    _blocks.push_back(new Block(9, 10));
    _blocks.push_back(new Block(10, 10));
    
    
    _blocks.push_back(new Block(10, 0));
    _blocks.push_back(new Block(10, 1));
    _blocks.push_back(new Block(10, 2));
    _blocks.push_back(new Block(10, 3));
    _blocks.push_back(new Block(10, 4));
    _blocks.push_back(new Block(10, 5));
    _blocks.push_back(new Block(10, 6));
    _blocks.push_back(new Block(10, 7));
    _blocks.push_back(new Block(10, 8));
    _blocks.push_back(new Block(10, 9));

    _bg_texture.loadFromFile("./res/textures/world/floor.png");
    _bg.setTexture(&_bg_texture);
    _bg.setTextureRect(sf::IntRect(0, 0, 1500, 1000));
    _bg_texture.setRepeated(true);
    _bg.setPosition(400, 0);
}

MainGame::~MainGame()
{
}


void MainGame::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_bg);
    for (auto &&b : _blocks)
    {
        target.draw(*b);
    }
    
    target.draw(_p);
}

void MainGame::update()
{
    _p.update(_blocks);
}
