#include "interf.h"
#include <SFML/Graphics.hpp>


interf::interf()
{
}

interf::interf(int x, int y,mapa *ma,sf::RenderWindow *wi)
{
	sizex = x;
	sizey = y;
	m = ma;
	w = wi;
	towerclick = 0;
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
	if(towerclick)
	sq.setSize(sf::Vector2f(15, 15));
	else
	sq.setSize(sf::Vector2f(12, 12));
	w->draw(sq);
	

}

void interf::checktbuild(sf::Vector2i poz)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (towerclick&&poz.y<m->getsizey())
		{
			int xt = (poz.x - 10) / 20;
			int yt = (poz.y - 10) / 20;

			m->addtower(3, 70, 1, xt, yt);
			towerclick = 0;
		}
		else if (m->pdist(poz, sf::Vector2i(20, 30 + m->getsizey())) < 10)
			towerclick = 1;
	}

}

interf::~interf()
{
}
