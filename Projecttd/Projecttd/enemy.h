#pragma once
#include <SFML/Graphics.hpp>

class enemy : public sf::CircleShape
{
	float maxhp;
	float maxspeed;
	float armor;
	float frostr;
	float slow;
public:
	float hp;
	float dist;
	float speed;

	void takedmg(float dm,float fdm);
	void updatee(float dt);
	enemy();
	enemy(float hp1, float speed1, float armor1);
	~enemy();
};