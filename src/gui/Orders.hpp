#ifndef ORDERS_HPP_
#define ORDERS_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

#include "../utils/Order.hpp"

class Orders : public sf::Drawable
{
private:
	std::vector<Order*> _orders;
	sf::RectangleShape _bg;
public:
	Orders();
	~Orders();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void mouseHandler(sf::Vector2f const &);
};

#endif
