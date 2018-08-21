#include "wawe.h"
//#include "enemy.h"


wawe::wawe()
{
}
wawe::wawe(int amount, float hp, float speed, float armor, float interval1)
{
	for (size_t i = 0; i < amount; i++)
	{

		e.push_back(new enemy(hp, speed, armor));
	}

	interval = interval1;
	wawetime = 0;
	for (size_t i = 0; i <amount; i++)
	{
		started.push_back(0);
	}
}
void wawe::updatew(float dt, mapa &m)
{
	for (size_t i = 0; i <e.size(); i++)
	{
		if (wawetime>i*interval&&started[i] == 0)
		{
			m.eom.push_back(e[i]);
			started[i] = 1;
		}
	}
	
	
		m.updatepos(dt);
	
	wawetime += dt / 1000;
}
wawe::~wawe()
{
}