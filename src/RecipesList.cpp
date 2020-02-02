#include "RecipesList.hpp"

RecipesList * RecipesList::instance = nullptr;

RecipesList::RecipesList()
{
    _recipes.push_back(new Recipe("Armure", "Plaque de fer", "Plaque de fer", DECOMPOSER));
    _recipes.push_back(new Recipe("Plaque de fer", "Plaque de fer neuve", SCREWDRIVER));
   // _recipes.push_back(new Recipe("f", "fe", Block::SCREWDRIVER));
   // _recipes.push_back(new Recipe("f", "fe", Block::SCREWDRIVER));
}

bool RecipesList::exist(std::string const & name, Type type)
{
    return std::any_of(_recipes.begin(), _recipes.end(), [&](Recipe * r){return r->input == name && r->tool == type;});
}

std::vector<std::string> RecipesList::getRecipeOutput(std::string input, Type tool) const
{
    std::vector<std::string> outs;
    for (auto &&r : _recipes)
        if (r->input == input && r->tool == tool)
            return r->outputs;
    return outs;
}