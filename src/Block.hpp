#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <SFML/Graphics.hpp>

class Block : public sf::Drawable
{
public:
	enum Type{ SCREWDRIVER};
private:
	sf::RectangleShape _bg_sprite, _fg_sprite;
	sf::Texture _bg, _fg;
	Type _type;
public:
	Block(int, int);
	Block(int, int, Type);
	~Block();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	bool contains(sf::Vector2f const &) const;
};

#endif
