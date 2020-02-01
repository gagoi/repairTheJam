#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <vector>
#include "../gui/OrderItem.hpp"
#include "BrokenItem.hpp"

class Order : public sf::Drawable
{
private:
	std::vector<OrderItem*> _items;
public:
	Order();
	~Order();
	void add(BrokenItem * item) {_items.push_back(new OrderItem(item, _items.size() + 1));};
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void mouseHandler(sf::Vector2f const &);
};

#endif
