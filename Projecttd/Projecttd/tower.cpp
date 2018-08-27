#include "tower.h"


tower::tower(float d, float r, float s, int x, int y)
{
	dmg = d;
	fdmg = 0;
	range = r;
	sps = s;
	tfls = 0;
	lvl = 1;
	setPosition(sf::Vector2f(20 + 20 * x, 12 + 20 * y));
	setFillColor(sf::Color::Green);
	setRotation(45);
	setSize(sf::Vector2f(12, 12));
}


void tower::upgrade()
{
	dmg *= 2.2;
	range *= 1.1;
	sps *= 1.15;
	lvl++;
}
tower::~tower()
{
}