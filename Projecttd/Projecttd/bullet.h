#pragma once
#include <SFML/Graphics.hpp>
#include "tower.h"
class bullet
	:public sf::CircleShape
{
	sf::Vector2f spos;
	sf::Vector2f epos;
	float speed;
	float disttt;
	

public:
	int eind;
	tower* tow;


	sf::Vector2f norm(sf::Vector2f a);
	bullet(sf::Vector2f tpos, sf::Vector2f enpos,int ei, tower* t);
	bool update(float dt);

	bullet();
	~bullet();
};

