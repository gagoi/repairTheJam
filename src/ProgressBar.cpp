#include "ProgressBar.hpp"

ProgressBar::ProgressBar(sf::Vector2f const & pos, float const & percentage) : _bg(sf::RectangleShape(sf::Vector2f(40, 10))), _percentage(percentage)
{
    _bg.setPosition(pos);
    _fg.setPosition(pos);

    _bg.move(5, 35);
    _fg.move(7, 37);

    _bg.setFillColor(sf::Color::Black);
    _fg.setFillColor(sf::Color::Yellow);
}

ProgressBar::~ProgressBar()
{
}


void ProgressBar::draw(sf::RenderTarget & target, sf::RenderStates) const
{
    target.draw(_bg);
    target.draw(_fg);
}

void ProgressBar::update()
{
    _fg.setSize(sf::Vector2f(36 * _percentage, 6));
    if (_percentage >= 1)
        _fg.setFillColor(sf::Color::Green);
    else
        _fg.setFillColor(sf::Color::Yellow);
}