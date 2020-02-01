#include "MainGame.hpp"

MainGame::MainGame()
{
    _blocks.push_back(new Block(0, 0));
    _blocks.push_back(new Block(1, 0));
    _blocks.push_back(new Block(2, 0));
    _blocks.push_back(new Block(3, 0));
    _blocks.push_back(new Block(4, 0));
    _blocks.push_back(new Block(0, 1));
    _blocks.push_back(new Block(0, 2));
    _blocks.push_back(new Block(0, 3));
}

MainGame::~MainGame()
{
}


void MainGame::draw(sf::RenderTarget & target, sf::RenderStates) const
{
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
