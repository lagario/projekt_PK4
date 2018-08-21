#pragma once
#include <SFML/Graphics.hpp>

class enemy : public sf::CircleShape
{
public:
	float hp;
	float dist;
	float speed;
	float armor;
	//void updatepos(float d, mapa m);

	enemy();
	enemy(float hp1, float speed1, float armor1);
	~enemy();
};