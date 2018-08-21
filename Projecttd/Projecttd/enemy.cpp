#include "enemy.h"



enemy::enemy()
{
	setRadius(8);
	setFillColor(sf::Color::Red);
	setOrigin(getRadius(), getRadius());
	dist = 0;
	speed = 4;
	hp = 100;

}
enemy::enemy(float hp1, float speed1, float armor1)
{
	setRadius(8);
	setFillColor(sf::Color::Red);
	setOrigin(getRadius(), getRadius());
	setPosition(sf::Vector2f(-100, -100));
	hp = hp1;
	speed = speed1;
	armor = armor1;
	dist = 0;
}

void enemy::updatepos(float t, mapa m)
{
	dist += t * speed / 1000;
	setPosition(m.caclpos(dist).x * 20 + 20, m.caclpos(dist).y * 20 + 20);

}

enemy::~enemy()
{
}