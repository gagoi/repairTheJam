#ifndef ORDERS_HPP_
#define ORDERS_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

#include "../utils/Order.hpp"

class Orders : public sf::Drawable
{
private:
	static Orders * instance;
	std::vector<Order*> _orders;
	sf::RectangleShape _bg;
public:
	Orders();
	~Orders();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void mouseHandler(sf::Vector2f const &);
	static Orders * getInstance() {if (instance == nullptr) instance = new Orders(); return instance;};
	static void free() {delete instance;}
	static void insertOrder(BrokenItem * item) {Orders::getInstance()->_orders[0]->add(item);};
};

#endif
