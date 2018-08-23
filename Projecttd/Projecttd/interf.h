#pragma once
#include <SFML/Graphics.hpp>
#include "mapa.h"
class interf
{
	int sizex;
	int sizey;

	sf::RenderWindow w;
public:

	int **tab;

	interf(int x,int y);
	void disp(sf::RenderWindow *o);

	interf();
	~interf();
};

