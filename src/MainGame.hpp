#ifndef MAINGAME_HPP_
#define MAINGAME_HPP_

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Block.hpp"
#include <vector>

class MainGame : public sf::Drawable
{
private:
	Player _p;
	std::vector<Block*> _blocks;
	sf::RectangleShape _bg;
	sf::Texture _bg_texture;
public:
	MainGame();
	~MainGame();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void update();
};

#endif
