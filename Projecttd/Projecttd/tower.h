#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <vector>
#include <cmath>
class tower : public sf::RectangleShape
{
	float dmg;
	float range;
	float sps;
	float tfls;


public:
	tower(float d, float r, float s, int x, int y);
	void checke(std::vector<enemy*> &eom, float dt);

	~tower();
};
