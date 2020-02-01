#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <SFML/Graphics/RectangleShape.hpp>

class Item
{
private:
	sf::RectangleShape _sprite;
public:
	Item();
	~Item();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif
