#include "interf.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include<cmath>


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
	pressedt = 0;
	pressedu = 0;
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
	
	sq.setPosition(sf::Vector2f(18, 42 + m->getsizey()));
	sq.setSize(sf::Vector2f(4, 12));
	sq.setRotation(0);
	w->draw(sq);
	sf::CircleShape tr;
	tr.setPointCount(3);
	tr.setPosition(sf::Vector2f(20, 44 + m->getsizey()));
	tr.setFillColor(sf::Color::Green);
	tr.setRadius(6);
	tr.setOrigin(tr.getRadius(), tr.getRadius());
	w->draw(tr);



	std::ostringstream ss;
	ss << "gold: "<<m->gold;
	sf::Font font;

	
	if (font.loadFromFile("C:/Users/krzys/source/repos/projekt_PK4/Projecttd/Debug/sansation.ttf"))
	{
		sf::Text t;

		t.setFont(font);
		t.setCharacterSize(20);
		t.setPosition(100, 20 + m->getsizey());
		t.setString(ss.str());
		t.setFillColor(sf::Color::Black);
		w->draw(t);
	}
}

void interf::checktbuild(sf::Vector2i poz)
{
	int xt = (poz.x - 10) / 20;
	int yt = (poz.y - 10) / 20;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		
		if (towerclick&&poz.y<m->getsizey()&&m->tab[xt][yt]==1&&m->gold>=50)
		{
			m->gold -= 50;

			m->addtower(3, 70, 1.5, xt, yt);
			towerclick = 0;
		}
		else if (m->pdist(poz, sf::Vector2i(20, 30 + m->getsizey())) < 10)
			towerclick = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		if (!pressedt)
		{
			towerclick = !towerclick;
			pressedt = true;
		}
	}
	else
		pressedt = 0;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		if (!pressedu&&m->tab[xt][yt]==2)
		{
			int j = 0;
			for (size_t i = 0; i < m->tom.size(); i++)
			{
				int xt1 = (m->tom[i]->getPosition().x-10 )/ 20;
				int yt1 =( m->tom[i]->getPosition().y-10) / 20;
				if (xt1 == xt && yt == yt1)
				{
					j = i;
					break;
				}
			}
			
			int cost = 25 * pow(2, m->tom[j]->getl());
			if (m->gold >=cost )
			{
				m->tom[j]->upgrade();
				m->gold -= cost;
			}
				
		}
			pressedu = true;
	}
	else
		pressedu = 0;
}

interf::~interf()
{
}
