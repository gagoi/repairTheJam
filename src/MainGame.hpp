#ifndef MAINGAME_HPP_
#define MAINGAME_HPP_

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Block.hpp"
#include <vector>

class Block;
class Player;
class MainGame : public sf::Drawable
{
private:
	static MainGame * instance;
	Player * _p;
	std::vector<Block*> _blocks;
	sf::RectangleShape _bg;
	sf::Texture _bg_texture;
	MainGame();
public:
	~MainGame();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void update();
	std::vector<Block*> getDecomposerOut();
	static MainGame * getInstance() {if (instance == nullptr) instance = new MainGame(); return instance;}
	static void free() {delete instance;}
};

#endif
