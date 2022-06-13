//Child Class
#pragma once
//define libraries
#include "Ships.h"
#include <string>
using namespace std;

class AliShips :
	public Ships
{
public:
	AliShips(string name);
	std::string getHullType();
	void setHull(std::string titanium);
};