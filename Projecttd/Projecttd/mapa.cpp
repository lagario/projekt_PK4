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

mapa::~mapa()
{
}
