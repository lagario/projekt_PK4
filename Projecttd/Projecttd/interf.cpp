#include "interf.h"



interf::interf()
{
}

interf::interf(int x, int y,mapa *ma,sf::RenderWindow *wi)
{
	sizex = x;
	sizey = y;
	m = ma;
	w = wi;
	tab = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new int[y];
	}
}

void interf::disp()
{
	sf::RectangleShape sq;
	sq.setSize(sf::Vector2f(20, 20));
	sq.setFillColor(sf::Color::Cyan);

	for (size_t i = 0; i < sizex; i++)
	{
		for (int j=0; j < sizey; j++)
		{
			sq.setPosition(sf::Vector2f(10 + 20 * i,m->getsizey()+20 + 20 * j));
			w->draw(sq);
		}
	}

	sq.setPosition(sf::Vector2f(20,22+m->getsizey()));
	sq.setFillColor(sf::Color::Green);
	sq.setRotation(45);
	sq.setSize(sf::Vector2f(12, 12));
	w->draw(sq);

}

interf::~interf()
{
}
