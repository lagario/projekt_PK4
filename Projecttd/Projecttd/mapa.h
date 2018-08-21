#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class mapa
{

public:

	int sizex;
	int sizey;
	std::vector<sf::Vector2i> track;
	
	int**tab;
	mapa(int x, int y, std::vector<sf::Vector2i> track);
	void calctrack();
	sf::Vector2f caclpos(float d);
	float pdist(sf::Vector2i p1, sf::Vector2i p2);

	~mapa();
};
