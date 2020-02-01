#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <SFML/Graphics.hpp>
#include <random>
#include "utils/BrokenItem.hpp"
#include "gui/Orders.hpp"
#include "ProgressBar.hpp"
#include "RecipesList.hpp"

#include "EnumMachine.hpp"
class Block : public sf::Drawable
{
private:
	static std::mt19937 gen;
	static std::uniform_real_distribution<> rand;
	sf::RectangleShape _bg_sprite, _fg_sprite;
	sf::Texture _bg, _fg;
	Type _type;
	Item * _item;
	float _processTime;
	ProgressBar _bar;
public:
	Block(int, int);
	Block(int, int, Type);
	~Block();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	bool contains(sf::Vector2f const &) const;
	void update();
	Type getType() const {return _type;}
	Item * getItem() const {return _item;};
	void removeItem() {_item = nullptr;}
	void setItem(Item * item) {_item = item; _item->setPosition(_bg_sprite.getPosition());}
};

#endif
