#ifndef RECIPESLIST_HPP_
#define RECIPESLIST_HPP_

#include <string>
#include <vector>
#include "EnumMachine.hpp"
#include "Block.hpp"
#include <algorithm>

class RecipesList
{
private:
	static RecipesList * instance;
	struct Recipe {
		std::string input;
		std::vector<std::string> outputs;
		Type tool;

		Recipe(std::string const & in, std::string out1, Type t) : input(in), tool(t) 
		{
			outputs.push_back(out1);
		}

		Recipe(std::string const & in, std::string out1, std::string out2, Type t) : Recipe(in, out1, t)
		{
			outputs.push_back(out2);
		}

		Recipe(std::string const & in, std::string out1, std::string out2, std::string out3, Type t) : Recipe(in, out1, out2, t)
		{
			outputs.push_back(out3);
		}
	};

	std::vector<Recipe*> _recipes;
public:
	RecipesList();
	static RecipesList * getInstance() {if (instance == nullptr) instance = new RecipesList(); return instance;}
	void free() {delete instance;}
	bool exist(std::string const &, Type);
	std::vector<std::string> getRecipeOutput(std::string, Type) const;
};

#endif
