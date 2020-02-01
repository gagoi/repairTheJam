#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Item : public sf::Drawable
{
private:
	sf::Font _font;
	std::string _name;
	sf::RectangleShape _sprite;
	sf::Texture _texture;
	sf::Text _text;
	std::string _texturePath;
public:
	Item(std::string const &, std::string const &);
	~Item();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	std::string getName() const {return _name;}
	std::string const & getTexturePath() const {return _texturePath;}
	sf::Font const & getFont() const {return _font;}
	void setPosition(sf::Vector2f const & pos){_sprite.setPosition(pos);}
};

#endif
