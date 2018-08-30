#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "tower.h"
#include "enemy.h"
#include "bullet.h"
#include "gem.h"
#include "wawe.h"
class mapa
{
int sizex;
int sizey;

public:
	std::vector<wawe*> wawes;

	std::vector<tower*> tom;
	std::vector<enemy*> eom;
	std::vector<bullet*> bom;
	int getsizex() { return 20 * sizex; }
	int getsizey() { return 20 * sizey; }
	int gold;
	float mana;
	float mps;
	int wawenr ;
	std::vector<sf::Vector2i> track;
	bool isinmap(sf::Vector2f pos);
	bool isinmap(sf::Vector2i pos);
	
	int**tab;
	mapa(int x, int y, std::vector<sf::Vector2i> track);
	void calctrack();
	sf::Vector2f caclpos(float d);
	float pdist(sf::Vector2i , sf::Vector2i );
	float pdist(sf::Vector2f , sf::Vector2f );
	float pdist(sf::Vector2f , sf::Vector2i );
	void updatepos(float d);
	void updatewawes(float );
	void deletee(enemy* en);
	void addtower(float d, float r, float s, int x, int y);
	void addgem(tower*, int typ);

	void checke(float dt);
	void towershoot(tower* tow,sf::Vector2f epos,enemy* ei);

	~mapa();
};
