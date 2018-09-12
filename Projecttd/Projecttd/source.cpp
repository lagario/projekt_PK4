#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "interf.h"


int x = 35;
int y = 20;
mapa *m;
interf* inter;

void disp(sf::RenderWindow *o, mapa *m,interf* f)
{
	o->clear();
	sf::RectangleShape sq;
	sq.setSize(sf::Vector2f(20, 20));
	sq.setFillColor(sf::Color::White);
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			sq.setPosition(sf::Vector2f(10 + 20 * i, 10 + 20 * j));
			if (m->tab[i][j])
				o->draw(sq);
		}
	}
	for (size_t i = 0; i < m->tom.size(); i++)
	{
		o->draw(*m->tom[i]);
		if(m->tom[i]->g)
		{
			o->draw(*m->tom[i]->g);
		}
	}
	for (size_t i = 0; i <m->eom.size(); i++)
		o->draw(*m->eom[i]);

	for (size_t i = 0; i <m->bom.size(); i++)
		o->draw(*m->bom[i]);

	f->disp();
	o->display();
}
void deletem(mapa*m)
{
	if (m)
	{
		for (size_t i = 0; i < m->tom.size(); i++)
		{

			if (m->tom[i]->g)
			{
				delete m->tom[i]->g;
			}
			delete m->tom[i];
		}
		for (size_t i = 0; i < m->eom.size(); i++)
			delete m->eom[i];

		for (size_t i = 0; i < m->bom.size(); i++)
			delete m->bom[i];
		for (size_t i = 0; i < m->wawes.size(); i++)
			delete m->wawes[i];
	}
	delete m;

}
void init(sf::RenderWindow *o)
{
	delete inter;
	deletem(m);
	m = new mapa(x, y);
	inter = new interf(18, 7, m, o);

	m->addpoint(0, 4);
	m->addpoint(19, 4);
	m->addpoint(19, 11);
	m->addpoint(14, 11);
	m->addpoint(14, 2);
	m->addpoint(34, 2);
	m->calctrack();

	for (size_t i = 0; i < 100; i++)
	{
		m->wawes.push_back(new wawe(6, pow(2, pow(i, 0.7) + 1), 4, 1 + i, 0.3));
	}
}
void updategame(mapa*m,float dt)
{
	m->updatepos(dt);
	m->updatewawes(dt);
	m->checke(dt);
}


int main()
{
	
	sf::RenderWindow okno(sf::VideoMode(20 + 20 * x, 250 + 20 * y), "td");		okno.setFramerateLimit(60);
	
	
	init(&okno);

	sf::Clock timer;


	while (okno.isOpen()&&m->gamestate!=3)
	{	sf::Event event;	while (okno.pollEvent(event)) { if (event.type == sf::Event::Closed)okno.close(); } //while

		if (m->gamestate==0&&sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			m->gamestate = 1;//start

		sf::Vector2i poz = sf::Mouse::getPosition(okno);
		inter->checktbuild(poz);

		if (m->gamestate == 1)
		{
			float dt = timer.getElapsedTime().asMilliseconds();
			if (dt > 100) dt = 100;//
			updategame(m, dt);
			timer.restart();
		}
		disp(&okno, m, inter);
		if (m->gamestate == 2)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) init(&okno);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) m->gamestate=3;
		}
		
	} //while


	return 0;
}
			