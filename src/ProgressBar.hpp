#ifndef PROGRESSBAR_HPP_
#define PROGRESSBAR_HPP_

#include <SFML/Graphics.hpp>

class ProgressBar : public sf::Drawable
{
private:
	sf::RectangleShape _bg;
	sf::RectangleShape _fg;
	float const & _percentage;
public:
	ProgressBar(sf::Vector2f const &, float const & percentage);
	~ProgressBar();
	void draw(sf::RenderTarget &, sf::RenderStates) const;
	void update();
};

#endif
