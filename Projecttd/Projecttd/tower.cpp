#include "tower.h"


tower::tower(float d, float r, float s, int x, int y)
{
	dmg = d;
	range = r;
	sps = s;
	tfls = 0;
	lvl = 1;
	setPosition(sf::Vector2f(20 + 20 * x, 12 + 20 * y));
	setFillColor(sf::Color::Green);
	setRotation(45);
	setSize(sf::Vector2f(12, 12));
	g = nullptr;
}


void tower::upgrade()
{
	lvl++;
	dmg = 1 + lvl + lvl * lvl + pow(lvl, 3)*0.1 + pow(lvl, 4)*0.03 + pow(lvl, 5)*0.003;
	range += 8;
	sps *= 1.12;
	

	if(g)
	g->updatedmg(lvl);
}
tower::~tower()
{
}