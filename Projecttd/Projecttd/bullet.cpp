#include "bullet.h"

sf::Vector2f bullet::norm(sf::Vector2f a)
{
	float tmp=sqrt((a.x)*(a.x) + (a.y)*(a.y));
	
	return sf::Vector2f(a.x / tmp, a.y / tmp);
	
}
bullet::bullet(sf::Vector2f tpos, sf::Vector2f enpos,enemy* ei,tower* t)
{
	setFillColor(sf::Color::Magenta);
	setOrigin(0, 0);
	setPosition(tpos);
	setRadius(3);
	spos = tpos;
	epos = enpos;
	speed = 1;
	disttt= sqrt(((epos - spos).x)*((epos - spos).x) + ((epos - spos).y)*((epos - spos).y));
	en = ei;
	tow = t;
}

bool bullet::update(float dt)
{
	disttt -= dt * speed;
	if (disttt > 0)
		move(norm(epos - spos)*dt*speed);
	else
		return true;
	return 0;
}
bullet::bullet()
{
}


bullet::~bullet()
{
}
