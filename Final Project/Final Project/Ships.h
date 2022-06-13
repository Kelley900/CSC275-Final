//Parent Class
#pragma once
//define reference libraries
#include <string>
using namespace std;

class Ships
{
public:
	Ships(std::string name);
	void takeDamage(int hit);
	int fire();
	//virtual std::string getHullStrength() = 0;
	std::string getName();
	int getHealth();

private:
	std::string name;
	int health;

protected:
	std::string ht;
	int hp;
};
