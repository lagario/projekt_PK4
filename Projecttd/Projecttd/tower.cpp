#include "tower.h"


tower::tower(float d, float r, float s, int x, int y)
{
	dmg = d;
	fdmg = 0;
	range = r;
	sps = s;
	tfls = 0;
	setPosition(sf::Vector2f(20 + 20 * x, 12 + 20 * y));
	setFillColor(sf::Color::Green);
	setRotation(45);
	setSize(sf::Vector2f(12, 12));
}



void tower::dealdmg(std::vector<enemy*> &eom, enemy* ei)
{
	ei->takedmg(dmg,fdmg);
	if (ei->hp < 0.001)
	{
		std::vector<enemy*>::iterator it = eom.begin();
		while(it != eom.end()&&*it != ei)
		{
			it++;
		}
		if (it != eom.end())
		{
			eom.erase(it);
			delete ei;
		}
	}
}
tower::~tower()
{
}