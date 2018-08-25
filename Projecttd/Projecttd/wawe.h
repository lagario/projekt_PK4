#pragma once
#include <vector>
#include "enemy.h"
#include "mapa.h"
class wawe
{
	float whp;
	float wspeed;
	int wamount;
	float warmor;
public:
	//std::vector<enemy*> e;
	std::vector<int> started;
	float interval;
	float wawetime;
	wawe();

	wawe(int amount, float hp, float speed, float armor, float interval1);
	void updatew(float dt, mapa &m);


	~wawe();
};

