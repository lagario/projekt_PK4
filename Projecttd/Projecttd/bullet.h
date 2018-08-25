#pragma once
#include <SFML/Graphics.hpp>
#include "tower.h"
#include "enemy.h"
class bullet
	:public sf::CircleShape
{
	sf::Vector2f spos;
	sf::Vector2f epos;
	float speed;
	float disttt;
	

public:
	enemy* en;
	tower* tow;


	sf::Vector2f norm(sf::Vector2f a);
	bullet(sf::Vector2f tpos, sf::Vector2f enpos,enemy* ei, tower* t);
	bool update(float dt);

	bullet();
	~bullet();
};

