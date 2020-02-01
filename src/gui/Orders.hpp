#ifndef ORDERS_HPP_
#define ORDERS_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

class Orders : public sf::Drawable
{
private:
public:
	Orders();
	~Orders();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif
