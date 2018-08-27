#include <iostream>

#include <SFML/Graphics.hpp>
#include <cmath>
#include "mapa.h"
#include <vector>
#include "enemy.h"
#include "wawe.h"
#include "tower.h"
#include "interf.h"
#include "bullet.h"

int x = 30;
int y = 20;

void disp(sf::RenderWindow *o, mapa m)
{
	sf::RectangleShape sq;
	sq.setSize(sf::Vector2f(20, 20));
	sq.setFillColor(sf::Color::White);
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			sq.setPosition(sf::Vector2f(10 + 20 * i, 10 + 20 * j));
			if (m.tab[i][j])
				o->draw(sq);
		}
	}
	for (size_t i = 0; i < m.tom.size(); i++)
		o->draw(*m.tom[i]);
	
	for (size_t i = 0; i <m.eom.size(); i++)
		o->draw(*m.eom[i]);

	for (size_t i = 0; i <m.bom.size(); i++)
		o->draw(*m.bom[i]);
}

int main()
{
	sf::RenderWindow okno(sf::VideoMode(20 + 20 * x, 200 + 20 * y), "td");
	std::vector<sf::Vector2i> t;
	t.push_back(sf::Vector2i(0, 4));
	t.push_back(sf::Vector2i(19, 4));
	t.push_back(sf::Vector2i(19, 11));
	t.push_back(sf::Vector2i(14, 11));
	t.push_back(sf::Vector2i(14, 2));
	t.push_back(sf::Vector2i(29, 2));
	mapa m(x, y, t);
	interf inter(20, 5,&m,&okno);
	m.calctrack();
	std::vector<wawe*> wawes;
	for (size_t i = 0; i < 100; i++)
	{
		wawes.push_back(new wawe(8, pow(2,sqrt(i)+1), 4, 1+i, 0.3));
	}
	
	int wawenr = 1;

	//m.addtower(3, 68, 1.8, 15, 10 );
	m.addtower(3, 100, 2.6, 17, 10);


	
	sf::Clock timer;
	sf::Clock totalt;
	wawes[0]->updatew(0.01,m);
	while (okno.isOpen())
	{
		sf::Event event;	while (okno.pollEvent(event)) { if (event.type == sf::Event::Closed)okno.close(); } //while
		okno.clear();	okno.setFramerateLimit(60);

		sf::Vector2i poz = sf::Mouse::getPosition(okno);
		
		inter.checktbuild(poz);
		float dt = timer.getElapsedTime().asMilliseconds();
		for (size_t i = 0; i <wawenr; i++)
		{
			wawes[i]->updatew(dt, m);
		}
		m.updatepos(dt);
		if (m.eom.size() == 0&&wawes[wawenr-1]->wawetime>1&&wawenr<wawes.size()-1)
			wawenr++;

		m.checke(dt);

		timer.restart();
		disp(&okno, m);
		inter.disp();

		okno.display();
	} //while
	return 0;
}
			