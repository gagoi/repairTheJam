#ifndef BROKENITEM_HPP_
#define BROKENITEM_HPP_

#include "Item.hpp"
#include "Recipe.hpp"

class BrokenItem : public Item
{
private:
	Recipe _recipe;
public:
	BrokenItem();
	~BrokenItem();
	Recipe getRecipe() const {return _recipe;}
};

#endif
