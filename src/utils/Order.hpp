#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <vector>
#include "BrokenItem.hpp"

class Order
{
private:
	std::vector<BrokenItem> _items;
public:
	Order();
	~Order();
};

#endif
