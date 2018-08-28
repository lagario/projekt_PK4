#pragma once
#include <SFML/Graphics.hpp>
#include "mapa.h"
#include <sstream>
class interf
{
	int sizex;
	int sizey;
	bool towerclick;
	bool pressedt;
	bool pressedu;
	sf::Font font;
	sf::Text t1;
	sf::Text t2;

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

