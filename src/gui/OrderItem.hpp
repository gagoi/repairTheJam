#ifndef ORDERITEM_HPP_
#define ORDERITEM_HPP_

#include <SFML/Graphics.hpp>

#include "../utils/Item.hpp"

class OrderItem : public sf::Drawable
{
private:
	static constexpr int WIDTH = 300;
	static constexpr int HEIGHT = 45;
	sf::RectangleShape _bg;
	sf::RectangleShape _icon;
	sf::Text _label;
	sf::Texture _texture;
	bool _selected;
	std::string _item;
public:
	OrderItem(Item * item, int);
	~OrderItem();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void checkClick(sf::Vector2f const & pos);
	std::string getName() const {return _item;}
};

#endif
