#pragma once
#include <SFML/Graphics.hpp>
#include<cmath>
class gem : public sf::CircleShape
{
	int type;
	int lvl;

public:

	int gett() { return type; }
	float dmg;
	void updatedmg(int tlvl);
	int getl() { return lvl; }

	void upgrade() { lvl++; }

	gem(int ,sf::Vector2f );
	~gem();
};

