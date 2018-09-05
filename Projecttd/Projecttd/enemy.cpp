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
	fire = 0;
	fireres = 0;
}

void enemy::takedmg(float dm,float edm,int typedmg)
{	dm= (dm - sqrt(armor))*(100 / (100 + log(armor+1)));
	if (dm > 0)
	hp -= dm;

	hp -= edm;
	

	switch (typedmg)
	{
	case 1:
		slow += edm;
		fire -= edm;
		break;
	case 2:
		fire += edm;
		slow -= edm;
		break;



	default:
		break;
	}
	

}
void enemy::updatee(float dt)
{

	fire -= (0.5 + (0.2*fireres))*dt / 1000;
	fire *= pow(0.7, dt / 1000);

	if (fire < 0)
		fire = 0;
	if (slow < 0)
		slow = 0;

	
	if(fire>0)
	hp -= fire * dt / 1000;
	speed = maxspeed * (10 / (10 + sqrt(slow)));
	if (slow > 0)
	{
		
		slow -= (0.3 + (0.1*frostr))*dt / 1000;
		slow *= pow(0.9, dt / 1000);
		if (slow < 0)
			slow = 0;
	}
	setFillColor(sf::Color::Color((100 + 155 * hp / maxhp), 0, 0, 255));
	
}
enemy::~enemy()
{
}