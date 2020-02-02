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
	int size() const {return _items.size();}
	void remove(std::string item) {
		auto it = std::find_if(_items.begin(), _items.end(), [&](auto i){return i->getName() == item;});
		if (it != _items.end()) _items.erase(it);
	}
};

#endif
