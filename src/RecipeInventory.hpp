#ifndef RECIPEINVENTORY_HPP_
#define RECIPEINVENTORY_HPP_


#include <vector>
#include <string>

class RecipeInventory
{
private:
	std::vector<std::string> _items_names;
public:
	RecipeInventory();
	~RecipeInventory();
};

#endif
