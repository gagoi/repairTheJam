#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>
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
	void setPosition(sf::Vector2f const & pos){_sprite.setPosition(pos);_sprite.move(5, 5);}

	static std::string getTextureOf(std::string str) 
	{
		std::cout << str << std::endl;
		if (str == "Armure") return "items2.png";
		else if (str == "Plaque de fer") return "item3.png";
		else if (str == "Plaque de fer neuve") return "item4.png";
		else if (str == "Armure réparée") return "item5.png";
	}
};

#endif
