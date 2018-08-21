#include "tower.h"


tower::tower(float d, float r, float s, int x, int y)
{
	dmg = d;
	range = r;
	sps = s;
	tfls = 0;
	setPosition(sf::Vector2f(20 + 20 * x, 12 + 20 * y));
	setFillColor(sf::Color::Green);
	setRotation(45);
	setSize(sf::Vector2f(12, 12));
}

void tower::checke(std::vector<enemy*> &eom, float dt)
{
	tfls += dt;
	for (size_t i = 0; i < eom.size(); i++)
	{
		sf::Vector2f tmp((eom[i]->getPosition()) - getPosition());
		if (range>sqrt(tmp.x*tmp.x + tmp.y*tmp.y))
			if (tfls >= 1000.0f / sps)
			{
				eom[i]->hp -= dmg;//
				tfls = 0;
				if (eom[i]->hp <= 0)
				{
					delete eom[i];
					eom.erase(eom.begin() + i);

				}
			}

	}
}
tower::~tower()
{
}