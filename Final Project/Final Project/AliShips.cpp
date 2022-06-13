#include "AliShips.h"

AliShips::AliShips(std::string name) :Ships(name)
{
	this->hp = 50;
}

std::string AliShips::getHullType()
{
	return this->ht;
}

void AliShips::setHull(std::string titanim)
{
	this->ht = titanim;
}