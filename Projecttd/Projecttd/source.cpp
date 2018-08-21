#include <iostream>

#include <SFML/Graphics.hpp>
#include <cmath>
#include "mapa.h"
#include <vector>
#include "enemy.h"
#include "wawe.h"
#include "tower.h"

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

}

int main()
{

	std::vector<sf::Vector2i> t;
	t.push_back(sf::Vector2i(0, 4));
	t.push_back(sf::Vector2i(19, 4));
	t.push_back(sf::Vector2i(19, 11));
	t.push_back(sf::Vector2i(14, 11));
	t.push_back(sf::Vector2i(14, 2));
	t.push_back(sf::Vector2i(29, 2));
	mapa m(x, y, t);
	m.calctrack();

	std::vector<enemy*> eonmap;

	wawe w1(8, 4, 4, 1, 0.3);

	tower tow(10, 50, 2, 15, 10);
	m.tab[15][10] = 2;


	sf::RenderWindow okno(sf::VideoMode(20 + 20 * x, 200 + 20 * y), "td");
	sf::Clock timer;
	sf::Clock totalt;

	while (okno.isOpen())
	{
		sf::Event event;	while (okno.pollEvent(event)) { if (event.type == sf::Event::Closed)okno.close(); } //while
		okno.clear();	okno.setFramerateLimit(60);

		disp(&okno, m);
		float dt = timer.getElapsedTime().asMilliseconds();
		w1.updatew(dt, m, eonmap);

		tow.checke(eonmap, dt);

		timer.restart();

		for (size_t i = 0; i <eonmap.size(); i++)
		{

			okno.draw(*eonmap[i]);
		}
		okno.draw(tow);


		okno.display();
	} //while
	return 0;
}
			