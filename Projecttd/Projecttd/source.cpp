#include <iostream>

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "interf.h"


int x = 35;
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
	{
		o->draw(*m.tom[i]);
		if(m.tom[i]->g)
		{
			o->draw(*m.tom[i]->g);
		}
	}
	for (size_t i = 0; i <m.eom.size(); i++)
		o->draw(*m.eom[i]);

	for (size_t i = 0; i <m.bom.size(); i++)
		o->draw(*m.bom[i]);
}

int main()
{
	sf::RenderWindow okno(sf::VideoMode(20 + 20 * x, 250 + 20 * y), "td");
	std::vector<sf::Vector2i> t;
	t.push_back(sf::Vector2i(0, 4));
	t.push_back(sf::Vector2i(19, 4));
	t.push_back(sf::Vector2i(19, 11));
	t.push_back(sf::Vector2i(14, 11));
	t.push_back(sf::Vector2i(14, 2));
	t.push_back(sf::Vector2i(34, 2));
	mapa m(x, y, t);
	interf inter(18, 7,&m,&okno);

	for (size_t i = 0; i < 100; i++)
	{
		m.wawes.push_back(new wawe(6, pow(2.5,sqrt(i)+1), 4, 1+i, 0.3));
	}
	
	

	m.addtower(3, 100, 1, 17, 10);
	m.addgem(m.tom[0], 2);


	sf::Clock timer;
	sf::Clock totalt;
	//wawes[0]->updatew(0.01,m);
	while (okno.isOpen()&&m.gamestate==1)
	{
		sf::Event event;	while (okno.pollEvent(event)) { if (event.type == sf::Event::Closed)okno.close(); } //while
		okno.clear();	okno.setFramerateLimit(60);

		sf::Vector2i poz = sf::Mouse::getPosition(okno);
		
		inter.checktbuild(poz);
		float dt = timer.getElapsedTime().asMilliseconds();
		
		m.updatepos(dt);
		m.updatewawes(dt);
		m.checke(dt);

		timer.restart();

		inter.disp();
		disp(&okno, m);
		okno.display();

	} //while


	return 0;
}
			