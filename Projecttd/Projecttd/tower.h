#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <vector>
#include <cmath>
class tower : public sf::RectangleShape
{
	float fdmg;
	
public:

	float dmg;
	float range;
	float sps;
	float tfls;//  czas od ostatniego strzalu
	

	
	void dealdmg(std::vector<enemy*> &eom, enemy* ei);
	tower(float d, float r, float s, int x, int y);

	~tower();
};

