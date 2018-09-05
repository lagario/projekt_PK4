#pragma once
#include <vector>
#include "enemy.h"
//#include "mapa.h"
class wawe
{
	float whp;
	float wspeed;
	int wamount;
	float warmor;
	float interval;
	std::vector<int> started;
public:
	

	float wawetime;
	wawe();

	wawe(int amount, float hp, float speed, float armor, float interval1);
	void updatew(float dt, std::vector<enemy*> &eom);


	~wawe();
};

