#ifndef RECIPESLIST_HPP_
#define RECIPESLIST_HPP_

#include <string>
#include <vector>
#include "EnumMachine.hpp"
#include "Block.hpp"
#include <algorithm>
#include "RecipeInventory.hpp"
class RecipesList
{
private:
	static RecipesList * instance;
	struct Recipe {
		RecipeInventory input;
		RecipeInventory output;
		Type tool;

		Recipe(RecipeInventory in, RecipeInventory out, Type t) : input(in), output(out), tool(t) {}
	};

	std::vector<Recipe*> _recipes;
public:
	RecipesList();
	static RecipesList * getInstance() {if (instance == nullptr) instance = new RecipesList(); return instance;}
	void free() {delete instance;}
	bool exist(std::string const &, Type);
	RecipeInventory const * getRecipeOutput(RecipeInventory, Type) const;
};

#endif
