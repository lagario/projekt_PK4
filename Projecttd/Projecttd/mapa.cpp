#include "mapa.h"
#include <cmath>
#include <algorithm>


mapa::mapa(int x, int y, std::vector<sf::Vector2i> track1)
{
	sizex = x;
	sizey = y;
	track = track1;
	tab = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new int[y];
	}

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

	return sf::Vector2f(track[track.size() - 1]);

}

void mapa::updatepos(float t)
{
	for (size_t i = 0; i < eom.size(); i++)
	{




		eom[i]->dist += t * eom[i]->speed / 1000;
		eom[i]->setPosition(caclpos(eom[i]->dist).x * 20 + 20, caclpos(eom[i]->dist).y * 20 + 20);
	}


	for (size_t i = 0; i < bom.size(); i++)
	{
		bom[i]->update(t);
	}
}

void mapa::addtower(float d, float r, float s, int x, int y)
{
	tom.push_back(new tower(d, r, s, x, y));
	tab[x][y] = 2;
}

void mapa::checke(float dt)
{
	for (size_t i = 0; i < tom.size(); i++)
	{
		//tom[i]->checke(eom, dt);
		tom[i]->tfls += dt;
		for (size_t j = 0; j < eom.size(); j++)
		{
			sf::Vector2f tmp((eom[j]->getPosition()) - tom[i]->getPosition());
			if (tom[i]->range>sqrt(tmp.x*tmp.x + tmp.y*tmp.y))
				if (tom[i]->tfls >= 1000.0f / tom[i]->sps)
				{

					towershoot(tom[i],eom[j]->getPosition(),j);

					//eom[j]->hp -= tom[i]->dmg;//
					//tom[i]->tfls = 0;
					//if (eom[j]->hp <= 0)
					//{
					//	delete eom[j];
					//	eom.erase(eom.begin() + j);

					//}
				}

		}
	}
}

void mapa::towershoot(tower* tow, sf::Vector2f epos, int ei)
{
	tow->tfls = 0;
	bom.push_back(new bullet(tow->getPosition(), epos, ei,tow));

}


mapa::~mapa()
{
}
