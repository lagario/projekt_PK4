#pragma once
#include <SFML/Graphics.hpp>

class enemy : public sf::CircleShape
{
	float maxhp;
	float maxspeed;
	float armor;
	float frostr;
	float slow;
	float fireres;
	float fire;
public:
	float hp;
	float dist;
	float speed;
	float geta() { return armor; }
	float gets() { return slow; }
	float getf() { return fire; }

	void takedmg(float dm,float edm, int typedmg);
	void updatee(float dt);
	enemy();
	enemy(float hp1, float speed1, float armor1);
	~enemy();
};