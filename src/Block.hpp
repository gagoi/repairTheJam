#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <SFML/Graphics.hpp>

class Block : public sf::Drawable
{
private:
	sf::RectangleShape _sprite;
	sf::Texture _bg;
public:
	Block(int, int);
	~Block();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	bool contains(sf::Vector2f const &) const;
};

#endif
