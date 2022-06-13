#include "Ships.h"

Ships::Ships(std::string name)
{
	this->name = name;
	this->health = 200;
	this->hp = 10;
}

void Ships::takeDamage(int hit)
{
	this->health -= hit;
	if (this->health < 0)
	{
		this->health = 0;
	}
}

int Ships::fire()
{
	return this->hp;
}
std::string Ships::getName()
{
	return this->name;
}

int Ships::getHealth()
{
	return this->health;
}