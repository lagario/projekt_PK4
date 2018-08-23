#pragma once
#include <SFML/Graphics.hpp>
#include "mapa.h"
class interf
{
	int sizex;
	int sizey;

	sf::RenderWindow *w;
	mapa *m;
public:

	int **tab;

	interf(int x,int y, mapa *ma, sf::RenderWindow *wi);
	void disp();

	interf();
	~interf();
};

