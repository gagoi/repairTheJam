#include "RecipeInventory.hpp"

RecipeInventory::RecipeInventory(std::string item1)
{
    push_back(item1);
}

RecipeInventory::RecipeInventory(std::string item1, std::string item2) : RecipeInventory(item1)
{
    push_back(item2);
}

RecipeInventory::RecipeInventory(std::string item1, std::string item2, std::string item3) : RecipeInventory(item1, item2)
{
    push_back(item3);
}