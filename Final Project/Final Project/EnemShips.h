//Child Class
#pragma once
//define libraries
#include "Ships.h"
#include <string>
using namespace std;

class EnemShips :
	public Ships
{
public:
	EnemShips(string name);
	std::string getHullType();
	void setHull(std::string titanium);
};