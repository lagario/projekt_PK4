#pragma once
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <vector>
#include <cmath>
class tower : public sf::RectangleShape
{
	
public:

	float dmg;
	float range;
	float sps;
	float tfls;//  czas od ostatniego strzalu
	


	void dealdmg(std::vector<enemy*> &eom, enemy* ei);
	tower(float d, float r, float s, int x, int y);
	void checke(std::vector<enemy*> &eom, float dt);//
	//void shoot(int ei,sf::Vector2f epos);
	~tower();
};

