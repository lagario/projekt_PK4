#include "interf.h"



interf::interf()
{
}

interf::interf(int x, int y)
{
	sizex = x;
	sizey = y;
	tab = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new int[y];
	}
}

void interf::disp(sf::RenderWindow *o)
{
	sf::RectangleShape sq;
	sq.setSize(sf::Vector2f(20, 20));
	sq.setFillColor(sf::Color::Cyan);

	for (size_t i = 0; i < sizex; i++)
	{
		for (int j=0; j < sizey; j++)
		{
			sq.setPosition(sf::Vector2f(10 + 20 * i,400+10 + 20 * j));
			o->draw(sq);
		}
	}
}

interf::~interf()
{
}
