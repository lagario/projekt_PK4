#include "mapa.h"
#include <cmath>
#include <algorithm>


mapa::mapa(int x, int y, std::vector<sf::Vector2i> track1)
{
	sizex = x;
	sizey = y;
	track = track1;
	gold = 150;
	mana = 100000;
	mps = 1;
	wawenr = 1;
	gamestate = 1;
	tab = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new int[y];
	}
	calctrack();
}

void mapa::calctrack()
{
	for (size_t i = 0; i < sizex; i++)
		for (size_t j = 0; j < sizey; j++)
			tab[i][j] = 1;





	for (size_t i = 1; i < track.size(); i++)
	{
		sf::Vector2i p(track[i - 1].x, track[i - 1].y), q(track[i].x, track[i].y);

		tab[track[i].x][track[i].y] = 0;
		if (p.x == q.x)
			for (size_t j = std::min(q.y, p.y); j < std::max(p.y, q.y); j++)
			{
				tab[p.x][j] = 0;
			}
		if (p.y == q.y)
			for (size_t j = std::min(q.x, p.x); j < std::max(p.x, q.x); j++)
			{


				tab[j][p.y] = 0;

			}


	}

}

float mapa::pdist(sf::Vector2i p1, sf::Vector2i p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
float mapa::pdist(sf::Vector2f p1, sf::Vector2f p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
float mapa::pdist(sf::Vector2f p1, sf::Vector2i p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
bool mapa::isinmap(sf::Vector2f pos)
{
	if (pos.x > 10 && pos.y > 10 && pos.x < 20 * sizex + 10 && sizey < 20 * sizey + 10)
		return true;
	return 0;
}
bool mapa::isinmap(sf::Vector2i pos)
{
	if (pos.x > 10 && pos.y > 10 && pos.x < 20 * sizex + 10 && sizey < 20 * sizey + 10)
		return true;
	return 0;
}

sf::Vector2f mapa::caclpos(float d)
{

	for (size_t i = 1; i < track.size(); i++)
	{
		sf::Vector2i p(track[i - 1].x, track[i - 1].y), q(track[i].x, track[i].y);

		if (d>pdist(p, q))
			d -= pdist(p, q);
		else
		{
			if (p.x == q.x&&p.y < q.y) return sf::Vector2f(p.x, p.y + d);
			if (p.x == q.x&&p.y > q.y) return sf::Vector2f(p.x, p.y - d);
			if (p.y == q.y&&p.x < q.x) return sf::Vector2f(p.x + d, p.y);
			if (p.y == q.y&&p.x > q.x) return sf::Vector2f(p.x - d, p.y);
		}
	}

	gamestate = 2;
	return sf::Vector2f(track[track.size() - 1]);

}

void mapa::updatepos(float t)
{
	
	for (size_t i = 0; i < bom.size(); i++)
	{
		
		if (bom[i]->update(t))
		{

			bom[i]->en->takedmg(bom[i]->tow->dmg, (bom[i]->tow->g==nullptr?0: bom[i]->tow->g->dmg), 
				(bom[i]->tow->g == nullptr ? 0 : bom[i]->tow->g->gett()));
			if (bom[i]->en->hp < 0.0001)		
				deletee(bom[i]->en);
			
			else
			{
				delete bom[i];
				bom.erase(bom.begin() + i);
			}
		}
	}
	for (size_t i = 0; i < eom.size(); i++)
	{
		enemy *e = eom[i];
		e->dist += t * e->speed / 1000;
		e->setPosition(caclpos(e->dist).x * 20 + 20, caclpos(e->dist).y * 20 + 20);

		e->updatee(t);
		if (e->hp < 0.0001)
		{

			deletee(e);
			i--;
		}
	}

	for (size_t i = 0; i < eom.size(); i++)
	{

	}

}

void mapa::updatewawes(float d)
{
	for (size_t i = 0; i <wawenr; i++)
	{
		wawes[i]->updatew(d,eom);
	}

	mana += mps * d/1000;
	if (wawes[wawenr - 1]->wawetime > 15)
		wawenr++;
}

void mapa::nextw()
{
	mana += mps * (15 - wawes[wawenr - 1]->wawetime);
	wawenr++;
}

void mapa::addtower(float d, float r, float s, int x, int y)
{
	tom.push_back(new tower(d, r, s, x, y));
	tab[x][y] = 2;
	gold -= 50;
}

void mapa::checke(float dt)
{
	for (size_t i = 0; i < tom.size(); i++)
	{
		
		tom[i]->tfls += dt;
		for (size_t j = 0; j < eom.size(); j++)
		{
			sf::Vector2f tmp((eom[j]->getPosition()) - tom[i]->getPosition());
			if (tom[i]->range>sqrt(tmp.x*tmp.x + tmp.y*tmp.y))
				if (tom[i]->tfls >= 1000.0f / tom[i]->sps)
				{

					towershoot(tom[i],eom[j]->getPosition(),eom[j]);

				}

		}
	}
}

void mapa::addgem(tower* t, int typ)
{
	if (t->g == nullptr&&mana>50)
	{
		t->g = new gem(typ, t->getPosition()-sf::Vector2f(4,-4));
		mana -= 50;
	}
}

void mapa::towershoot(tower* tow, sf::Vector2f epos, enemy* ei)
{
	tow->tfls = 0;
	bom.push_back(new bullet(tow->getPosition(), epos, ei,tow));

}
void mapa::deletee(enemy *en)
{
	for (size_t i2 = 0; i2 < bom.size(); i2++)
	{
		if (bom[i2]->en == en)
		{
			delete bom[i2];
			bom.erase(bom.begin() + i2);
			i2--;
		}

	}
		std::vector<enemy*>::iterator it = eom.begin();
		while (it != eom.end() && *it != en)
		{
			it++;
		}
		if (it != eom.end())
		{
			eom.erase(it);
			delete en;
		}
		gold += 2+pow(wawenr, 1.4);
}



mapa::~mapa()
{
}
