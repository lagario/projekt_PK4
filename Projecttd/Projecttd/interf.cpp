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
	pressedmouse = 0;
	if (!font.loadFromFile("sansation.ttf"))
	{
		//error
	}
	
}

tower*interf::gettptr(int x, int y)
{
	int j = 0;
	for (size_t i = 0; i < m->tom.size(); i++)
	{
		int xt1 = (m->tom[i]->getPosition().x - 10) / 20;
		int yt1 = (m->tom[i]->getPosition().y - 10) / 20;
		if (xt1 == x && y == yt1)
		{
			j = i;
			break;
		}
	}
	return m->tom[j];
}

void interf::disp()
{
	sf::RectangleShape sq;
	sq.setSize(sf::Vector2f(20*sizex, 20*sizey));
	sq.setFillColor(sf::Color::Cyan);
	sq.setPosition(10 ,m->getsizey()+20);
	w->draw(sq);

	sq.setFillColor(sf::Color::Yellow);
	sq.setSize(sf::Vector2f(300, 20 * sizey));
	sq.setPosition(20+20*sizex, m->getsizey() + 20);
	w->draw(sq);

	sq.setPosition(10, m->getsizey()+sizey*20 + 30);
	sq.setSize(sf::Vector2f(sizex*20, 50));
	w->draw(sq);

	sq.setSize(sf::Vector2f(50, 50));
	sq.setPosition(20 + 20 * sizex, m->getsizey() + sizey * 20 + 30);
	sq.setFillColor(sf::Color::Color(220, 220, 220, 255));
	w->draw(sq);

	sq.setSize(sf::Vector2f(65, 50));
	sq.setPosition(300, m->getsizey() + 25);
	w->draw(sq);

	sq.setSize(sf::Vector2f(150, 50));
	sq.setPosition(90 + 20 * sizex, m->getsizey() + sizey * 20 + 30);
	w->draw(sq);

	
	

	sq.setPosition(20,22+m->getsizey());
	sq.setFillColor(sf::Color::Green);
	sq.setRotation(45);
	if(towerclick)
	sq.setSize(sf::Vector2f(15, 15));
	else
	sq.setSize(sf::Vector2f(12, 12));
	w->draw(sq);
	

	sq.setPosition(18, 48 + m->getsizey());
	sq.setSize(sf::Vector2f(4, 12));
	sq.setRotation(0);
	w->draw(sq);
	sf::CircleShape tr;
	tr.setPointCount(3);
	tr.setPosition(20, 50 + m->getsizey());
	tr.setFillColor(sf::Color::Green);
	tr.setRadius(6);
	tr.setOrigin(tr.getRadius(), tr.getRadius());
	w->draw(tr);
	tr.setFillColor(sf::Color::Blue);
	sq.setFillColor(sf::Color::Blue);
	tr.setPosition(20, 88 + m->getsizey());
	sq.setPosition(18, 86 + m->getsizey());
	w->draw(tr);
	w->draw(sq);

	tr.setPosition(20, 70 + m->getsizey());
	tr.setPointCount(30);
	w->draw(tr);
	tr.setPosition(20, 106 + m->getsizey());
	tr.setFillColor(sf::Color::Red);
	w->draw(tr);


	float x = m->mps;
	int costm = x * x * 15 + x * 5 + 30;
	std::ostringstream ss1, ss2,ss3;
	//ss1.precision(4);
	ss1 << "gold: "<<m->gold<<"\nmana: "<<floor(m->mana)<<" mps: "<<m->mps;
	ss2 << "wawe: " << m->wawenr;
	ss3 << "+1 mps\ncost: " << costm;
	
	
	
	
	
		

		t1.setFont(font);
		t1.setCharacterSize(20);
		t1.setPosition(120, 20 + m->getsizey());
		t1.setString(ss1.str());
		t1.setFillColor(sf::Color::Black);
		w->draw(t1);
		w->draw(t2);
		w->draw(t4);
		
		t3.setFont(font);
		t3.setCharacterSize(20);
		t3.setPosition(20, 40 + m->getsizey()+sizey*20);
		t3.setString(ss2.str());
		t3.setFillColor(sf::Color::Black);
		w->draw(t3);
		t3.setPosition(25 + 20 * sizex, m->getsizey() + sizey * 20 + 40);
		t3.setString("next");
		w->draw(t3);

		t3.setCharacterSize(18);
		t3.setPosition(40, m->getsizey()+ 18);
		t3.setString("T+click\nU\nB+click\nL\nR+click");
		w->draw(t3);

		t3.setPosition(300, m->getsizey() + 30);
		t3.setCharacterSize(12);
		t3.setString(ss3.str());
		w->draw(t3);
		if (m->gamestate == 2)
		{
			t3.setPosition(20, m->getsizey() -100);
			t3.setCharacterSize(25);
			t3.setString("GAME OVER\nrestart?(Y/N)");
			w->draw(t3);
		}
	
}



void interf::checktbuild(sf::Vector2i poz)
{
	bool mp = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	

	std::ostringstream ss2;
	int xt = (poz.x - 10) / 20;
	int yt = (poz.y - 10) / 20;

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

	if (mp)
	{

		if (towerclick&&poz.y < m->getsizey() && m->tab[xt][yt] == 1 && m->gold >= 50)
		{
			

			m->addtower(3, 70, 1.5, xt, yt);
			towerclick = 0;
		}
		else if (m->pdist(poz, sf::Vector2i(20, 30 + m->getsizey())) < 10)
			towerclick = 1;
	}



	if (m->isinmap(poz))
	{
		if (m->tab[xt][yt] == 2)
		{

			tower* p = gettptr(xt, yt);
			std::ostringstream ss1;
			ss1.precision(4);
			ss1 << "dmg: " << p->dmg << "\nrange: " << p->range << "\nspeed: " << p->sps << "\ngemdmg: " << (p->g == nullptr ? 0 : p->g->dmg)
				<< "\ntower lvl: " << p->getl() << "  lvlup cost: " << 25 * pow(2, p->getl()) << "\ngem lvl: ";
			if (p->g)
			{
				ss1 << (p->g == nullptr ? 0 : p->g->getl())
					<< "  upg mana cost: " << 25 * pow(2, p->g->getl());
			}

			t2.setFont(font);
			t2.setCharacterSize(18);
			t2.setPosition(30 + sizex * 20, 20 + m->getsizey());
			t2.setString(ss1.str());
			t2.setFillColor(sf::Color::Black);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			if (!pressedu&&m->tab[xt][yt] == 2)
			{
				tower*p = gettptr(xt, yt);

				int cost = 25 * pow(2, p->getl());
				if (m->gold >= cost)
				{
					p->upgrade();
					m->gold -= cost;
				}

			}
			pressedu = true;
		}
		else
			pressedu = 0;

		if (mp && sf::Keyboard::isKeyPressed(sf::Keyboard::B) && m->tab[xt][yt] == 2)
		{
			tower*p = gettptr(xt, yt);
			m->addgem(p, 1);
		}

		if (mp && sf::Keyboard::isKeyPressed(sf::Keyboard::R) && 
			m->tab[xt][yt] == 2)
		{
			tower*p = gettptr(xt, yt);
			m->addgem(p, 2);
		}

		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			if (m->tab[xt][yt] == 2 && pressedl == false)
			{
				pressedl = true;
				tower*p = gettptr(xt, yt);
				if (p->g)
				{
					int cost = 25 * pow(2, p->g->getl());
					if (m->mana > cost)
					{
						p->g->upgrade();
						p->g->updatedmg(p->getl());
						m->mana -= cost;
					}
				}
			}
		}
		else pressedl = 0;

		if (mp)
		{
			for (size_t i = 0; i < m->eom.size(); i++)
			{
				if (m->pdist(m->eom[i]->getPosition(), poz) < 10)
				{
					m->enem = m->eom[i];
				}
			}
		}
	}
	
	

		if (((mp && poz.x > 20 + 20 * sizex&& poz.y > m->getsizey() + sizey * 20 + 30 &&
			poz.x < 70 + 20 * sizex&& poz.y < m->getsizey() + sizey * 20 + 80)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			&& m->wawes[m->wawenr - 1]->wawetime > 1)
			m->nextw();
		
		if (!pressedmouse && ((mp && poz.x > 300 && poz.y > m->getsizey() + 25 &&
			poz.x < 365 && poz.y < m->getsizey() + 75)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::M)))
		{
			m->upgmps();
			pressedmouse = true;
		}
		if (!mp)
			pressedmouse = 0;



	

	if (m->enem!=nullptr)
	{
		ss2.precision(4);
		ss2 << "hp: " << m->enem->hp << " armor" << m->enem->geta() << "\nfire:" << m->enem->getf() << " speed: " << m->enem->speed;
		t4.setCharacterSize(15);
		t4.setFont(font);
		t4.setFillColor(sf::Color::Black);
		t4.setPosition(90 + 20 * sizex, m->getsizey() + sizey * 20 + 30);
		t4.setString(ss2.str());
	}
	else
	{
		t4.setString("");
	}
}



interf::~interf()
{
}
