#ifndef RECIPEINVENTORY_HPP_
#define RECIPEINVENTORY_HPP_


#include <vector>
#include <string>

class RecipeInventory : public std::vector<std::string>
{
public:
	RecipeInventory(std::string);
	RecipeInventory(std::string, std::string);
	RecipeInventory(std::string, std::string, std::string);
	bool operator==(RecipeInventory const & r1)
	{
		if (r1.size() != size()) return false;
		bool * compare = new bool[size()]{};

		for (unsigned int i = 0; i < size(); ++i)
		{
			for (unsigned int j = 0; j < size(); ++j)
			{
				if (at(i) == r1[j])
				{
					compare[i] = true;
					break;
				}
			}
			if (!compare[i]) return false;
		}
		return true;
	}
};

#endif
