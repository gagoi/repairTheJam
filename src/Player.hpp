#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include "Block.hpp"
#include <algorithm>

class Player : public sf::Drawable
{
private:
	enum Side {UP, DOWN, LEFT, RIGHT};
	sf::Texture _texture;
	sf::RectangleShape _sprite;
	bool checkCollide(Side, std::vector<Block*> const &, int) const;
public:
	Player();
	~Player();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void update(std::vector<Block*> const &);
};

#endif
