#ifndef ORDERS_HPP_
#define ORDERS_HPP_

#include <vector>
#include <SFML/Graphics.hpp>

#include "../utils/Order.hpp"
#include "algorithm"

class Orders : public sf::Drawable
{
private:
	static Orders * instance;
	std::vector<Order*> _orders;
	std::vector<std::string> _rep_names;
	sf::RectangleShape _bg;
public:
	Orders();
	~Orders();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void mouseHandler(sf::Vector2f const &);
	static Orders * getInstance() {if (instance == nullptr) instance = new Orders(); return instance;};
	static void free() {delete instance;}
	static void insertOrder(BrokenItem * item, Item * rep) {Orders::getInstance()->_orders[0]->add(item); Orders::getInstance()->_rep_names.push_back(rep->getName());};
	static void removeOrder(std::string item)
	{
		std::vector<std::string> & rep = getInstance()->_rep_names;
		auto it = std::find(rep.begin(), rep.end(), item);
		if (it != rep.end()) rep.erase(it);
		getInstance()->_orders[0]->remove(item.substr(0, item.length() - 6));
	}
};

#endif
