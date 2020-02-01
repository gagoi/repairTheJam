#ifndef BROKENITEM_HPP_
#define BROKENITEM_HPP_

#include "Item.hpp"

class BrokenItem : public Item
{
private:
public:
	BrokenItem(std::string const &, std::string const &);
	~BrokenItem();
};

#endif
