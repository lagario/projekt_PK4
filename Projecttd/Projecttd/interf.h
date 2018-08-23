#pragma once
#include <SFML/Graphics.hpp>
#include "mapa.h"
class interf
{
	int sizex;
	int sizey;
	bool towerclick;
	bool pressedt;

	sf::RenderWindow *w;
	mapa *m;
public:

	int **tab;

	interf(int x,int y, mapa *ma, sf::RenderWindow *wi);
	void checktbuild(sf::Vector2i poz);
	void disp();



	interf();
	~interf();
};

