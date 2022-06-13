#include "EnemShips.h"

EnemShips::EnemShips(std::string name) :Ships(name)
{
	this->hp = 50;
}

std::string EnemShips::getHullType()
{
	return this->ht;
}

void EnemShips::setHull(std::string titanim)
{
	this->ht = titanim;
}