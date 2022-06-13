#include "ChoiceCheck.h"
#include <iostream>
using namespace std;

bool ChoiceCheck(int choice)

try
	{
		//determin if the list option given is between 1 and 3
		if (choice > 3 || choice < 1)
		{
			cout << "Your input was outside the list peramiters. " << choice << " Good Bye." << endl;
			return false;
		}
		else
		{
			return (choice);
		}
	}
	catch (int exChoice)
	{
		//shows choice back to user
		cout << "You selected: " << choice << " Lets go!\n" << endl;
	}
