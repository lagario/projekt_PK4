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
	bool pressedl;
	bool pressedmouse;
	sf::Font font;
	sf::Text t1,t2,t3,t4;
	sf::RenderWindow *w;
	mapa *m;

	tower* gettptr(int, int);
public:

	//int **tab;

	interf(int x,int y, mapa *ma, sf::RenderWindow *wi);
	void checktbuild(sf::Vector2i poz);
	void disp();



	interf();
	~interf();
};

