#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <vector>
#include <cmath>
#include "gem.h"
class tower : public sf::RectangleShape
{
	int lvl;
	
	
public:
	gem*g;
	int getl() { return lvl; }
	float dmg;
	float range;
	float sps;
	float tfls;//  czas od ostatniego strzalu
	void upgrade();
	tower(float d, float r, float s, int x, int y);

	~tower();
};

