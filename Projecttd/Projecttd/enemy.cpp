#include "enemy.h"
#include<cmath>



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
	setFillColor(sf::Color::Color(255,0,0,255));
	setOrigin(getRadius(), getRadius());
	setPosition(sf::Vector2f(-100, -100));
	hp = hp1;
	maxhp = hp1;
	speed = speed1;
	maxspeed = speed1;
	armor = armor1;
	dist = 0;
	frostr = 0;
	slow = 0;
}

void enemy::takedmg(float dm,float fdm)
{
	hp -= (dm - sqrt(armor))*(100 / (100 + log(armor)));
	hp -= fdm;
	setFillColor(sf::Color::Color((100+155*hp/maxhp), 0, 0, 255));
	slow += fdm;


}
void enemy::updatee(float dt)
{
	
	if (slow > 0)
	{
		speed = maxspeed * (10 / (10 + sqrt(slow)));
		slow -= (0.3 + (0.1*frostr))*dt / 1000;
		slow *= pow(0.9, dt / 1000);
		if (slow < 0)
			slow = 0;
	}
}
enemy::~enemy()
{
}