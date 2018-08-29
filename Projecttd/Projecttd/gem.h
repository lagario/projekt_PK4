#pragma once
#include <SFML/Graphics.hpp>
#include<cmath>
class gem : public sf::CircleShape
{
	int type;
	int lvl;

public:
	float dmg;
	void updatedmg(int tlvl);

	gem(int ,sf::Vector2f );
	~gem();
};

