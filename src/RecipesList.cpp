#include "RecipesList.hpp"

RecipesList * RecipesList::instance = nullptr;

RecipesList::RecipesList()
{
    _recipes.push_back(new Recipe("Armure", "fe", "fe", DECOMPOSER));
   // _recipes.push_back(new Recipe("f", "fe", Block::SCREWDRIVER));
   // _recipes.push_back(new Recipe("f", "fe", Block::SCREWDRIVER));
}

bool RecipesList::exist(std::string const & name, Type type)
{
    return std::any_of(_recipes.begin(), _recipes.end(), [&](Recipe * r){return r->input == name && r->tool == type;});
}