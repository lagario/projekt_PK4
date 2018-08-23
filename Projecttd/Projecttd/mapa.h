#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "tower.h"
#include "enemy.h"
class mapa
{
int sizex;
int sizey;

public:

	std::vector<tower*> tom;
	std::vector<enemy*> eom;
	int getsizex() { return 20 * sizex; }
	int getsizey() { return 20 * sizey; }
	
	std::vector<sf::Vector2i> track;
	
	int**tab;
	mapa(int x, int y, std::vector<sf::Vector2i> track);
	void calctrack();
	sf::Vector2f caclpos(float d);
	float pdist(sf::Vector2i p1, sf::Vector2i p2);
	void updatepos(float d);

	void addtower(float d, float r, float s, int x, int y);

	void checke(float dt);

	~mapa();
};
