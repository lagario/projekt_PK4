#include "gem.h"



gem::gem(int typ,sf::Vector2f poz)
{
	type = typ;
	if (type == 1)
		setFillColor(sf::Color::Blue);
	setRadius(4);
	setOrigin(0, 0);
	lvl = 1;
	setPosition(poz);

	dmg = 2;
}
void gem::updatedmg(int tlvl)
{
	dmg = 2 * pow(1.6, lvl-1)*pow(1.2, tlvl-1);
}



gem::~gem()
{
}
