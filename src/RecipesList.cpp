#include "RecipesList.hpp"

RecipesList * RecipesList::instance = nullptr;

RecipesList::RecipesList()
{
    _recipes.push_back(new Recipe(RecipeInventory("Armure"), RecipeInventory("Plaque de fer", "Plaque de fer"), DECOMPOSER));
    _recipes.push_back(new Recipe(RecipeInventory("Plaque de fer"), RecipeInventory("Plaque de fer neuve"), SCREWDRIVER));
    _recipes.push_back(new Recipe(RecipeInventory("Plaque de fer neuve", "Plaque de fer neuve"), RecipeInventory("Armure neuve"), ASSEMBLER));
   // _recipes.push_back(new Recipe("f", "fe", Block::SCREWDRIVER));
   // _recipes.push_back(new Recipe("f", "fe", Block::SCREWDRIVER));
}

bool RecipesList::exist(std::string const & name, Type type)
{
    return std::any_of(_recipes.begin(), _recipes.end(), [&](Recipe * r){return r->input == name && r->tool == type;});
}

RecipeInventory const * RecipesList::getRecipeOutput(RecipeInventory input, Type tool) const
{
    for (auto &&r : _recipes)
        if (r->input == input && r->tool == tool)
            return &r->output;
    return nullptr;
}