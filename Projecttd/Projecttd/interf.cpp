#include "interf.h"
#include <SFML/Graphics.hpp>

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
	sq.setSize(sf::Vector2f(20*sizex, 20*sizey));
	sq.setFillColor(sf::Color::Cyan);

	
	sq.setPosition(sf::Vector2f(10 ,m->getsizey()+20));
	w->draw(sq);

	sq.setFillColor(sf::Color::Yellow);
	sq.setSize(sf::Vector2f(200, 20 * sizey));
	sq.setPosition(sf::Vector2f(20+20*sizex, m->getsizey() + 20));
	w->draw(sq);



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



	std::ostringstream ss1;
	
	ss1 << "gold: "<<m->gold;
	

	
	if (font.loadFromFile("C:/Users/krzys/source/repos/projekt_PK4/Projecttd/Debug/sansation.ttf"))
	{
		

		t1.setFont(font);
		t1.setCharacterSize(20);
		t1.setPosition(100, 20 + m->getsizey());
		t1.setString(ss1.str());
		t1.setFillColor(sf::Color::Black);
		w->draw(t1);
		w->draw(t2);
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

		if (m->tab[xt][yt] == 2)
		{
			int j = 0;
			for (size_t i = 0; i < m->tom.size(); i++)
			{
				int xt1 = (m->tom[i]->getPosition().x - 10) / 20;
				int yt1 = (m->tom[i]->getPosition().y - 10) / 20;
				if (xt1 == xt && yt == yt1)
				{
					j = i;
					break;
				}
			}
			;
			std::ostringstream ss1;
			ss1 << "dmg: " << m->tom[j]->dmg<< "\nrange: " << m->tom[j]->range << "\nspeed: " << m->tom[j]->sps;
			t2.setFont(font);
			t2.setCharacterSize(20);
			t2.setPosition(30+sizex*20, 20 + m->getsizey());
			t2.setString(ss1.str());
			t2.setFillColor(sf::Color::Black);
			//w->draw(t1);

		}



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
