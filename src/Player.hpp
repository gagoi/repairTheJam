#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include "Block.hpp"
#include <algorithm>

class Player : public sf::Drawable
{
private:
	enum Side {DOWN, LEFT, RIGHT, UP};
	int _cpt;
	Side _side;
	sf::Texture _texture;
	sf::RectangleShape _sprite;
	bool checkCollide(Side, std::vector<Block*> const &, int) const;
	Block* checkPeakUp(Side s, std::vector<Block*> const & blocks, int speed) const;
	void changeTexture(Side s);
	Item * _item;
public:
	Player();
	~Player();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void update(std::vector<Block*> const &);
};

#endif
