#ifndef RECIPES_HPP_
#define RECIPES_HPP_

#include "SFML/Graphics.hpp"

class Recipes : public sf::Drawable
{
private:
public:
	Recipes();
	~Recipes();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif
