// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Code by Kelley Kramer
//CSC275

/*
Final Project has the following:
 Opening screen with a description of the application and instructions (intro)
 Menu for the user to choose options (Menue)
 At least 4 classes total (Ships, EnemShips, AliShips, ChoiceCheck)
 File input and output processing (each round is saved to the winners.txt file, and option 3, from the list, will display them)
 Exception handling (if an option is selected out side of the 1-3 of the list, it will throw an erro)
 Inheritance (minimum 2 derived classes) (AliShips, EnemShips)
 Polymorphism (Overloading and overriding) (Player creation, and character ID)
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include "Ships.h"
#include "AliShips.h"
#include "EnemShips.h"
#include "ChoiceCheck.h"

using namespace std;

void startGame()
{
    cout << "\t\t *** BATTLE SIMULATION ***\n\n"
        "This game is an interactive simulation of a battle between\n"
        "an allied feet and an enemy fleet.  There are also nutral\n"
        "vessels in the area so be careful not to hit them!\n" << endl;
}
int determineAttacker()
{
    int test = rand() % 10;
    return (test >= 6) ? 1 : 0;
}

void WriteLineToFile(string winner)
{
    //Make a file object to use as a file handel
    ofstream myFile;

    //open file
    myFile.open("winners.txt", ios_base::app);

    //write one line of text to the file
    myFile << winner << std::endl;

    //Write to display line of text that was writen to file
    cout << winner << " -has been written to the winners.txt file\n";

    //Close the file
    myFile.close();
}


int main()
{
    int choice;
    int age;
    string name;
    string captain = "Captain ";
    string general = "General ";
    string ready;
    string retry;
    bool done = false;
    //create ships in the game
    AliShips escort("USS Picard");
    EnemShips destroyer("IKS Chekuv");
    //set hull types
    escort.setHull("titanium");
    destroyer.setHull("titanium");

    //random number generator to get random player ID
    int id = 1 + (rand() % 1000);

    startGame();
     
    //gives user optio to chose how to proceed
    cout << "To start the game please pick one of the following options:\n"
            "(selections made other than 1-3 will not be accepted):\n"
            "1. Start Game as Allied ship\n2. Start game as Enemy ship\n3. View previous scors" << endl;
    cin >> choice;
    //Checks to make sure the choice is greater than 3 otherwise will throw error
    ChoiceCheck(choice);

    //sets up the fuctions of the game based off user choice
    if (choice == 1)
    {
        cout << "\t\tWelcom to the Allied Fleet!\n" << endl;

        //this section will combine two strigs to give the players title
        cout << "To get started please tell us your Name: " << endl;
        cin >> name;
        cout << "\n\tWelcom abord " << captain + name << " We are happy to have you with us!\n" << endl;
        
        //this section will use the random number generator and add their age to it.
        cout << "Next we need to generate a unique ID for you.  Please tell us you age." << endl;
        cin >> age;
        cout << "\tThank you.  Your ID is: " << id + age << " Dont lost it!\n" << endl;
        
        //this just displays the players ship to them
        cout<<"Your ship is called: " << escort.getName()<< ".\nCongradulations! She is a fine ship\n"<< endl;

        //this section will start the game
        cout << "When you are ready, simply press 'r' or 'R' to start the battle!\n" << endl;
        cin >> ready;

        //defines the counter for the loops to kill
        int attack = 1;

        while (true)
        {
            //show the numbers of loops to kill and opponent
            cout << "Attack " << attack << ", run program.\n" << endl;

            //determins the attacker and the reciver randomly using the value of determineAttacker random number
            if (determineAttacker())
            {
                cout << escort.getName() << " Is firering on enemy vessel!" << endl;
                destroyer.takeDamage(escort.fire());
                Sleep(2000);
            }
            else
            {
                cout << destroyer.getName() << " Is firering on " << escort.getName() << "!" << endl;
                escort.takeDamage(destroyer.fire());
                Sleep(2000);
            }

            //determins when a players hull strength is at zero
            if (escort.getHealth() <= 0)
            {
                cout << escort.getName() << " has suffered a hull breach and is dead." << endl;
                              
                string winship = " IKS Chekuv";
                string enemy = "Enemy";
                string winner = enemy + winship;
                WriteLineToFile(winner);
                break;
            }
            if (destroyer.getHealth() <= 0)
            {
                cout << destroyer.getName() << " has suffered a hull breach and is dead." << endl;
                
                string winship = " USS Picard";
                string player = captain + name;
                string winner = name + winship;
                WriteLineToFile(winner);
                break;
            }
            cout << destroyer.getName() << "'s hull is now at " << destroyer.getHealth() << "!" << endl;
            cout << escort.getName() << " 's hull is now at " << escort.getHealth() << "!\n" << endl;

            //update the simulation number
            attack++;
        }
    }
    else if (choice == 2)
    {
        cout << "\t\tWelcome Warrior! Our fleet is honored by your presce!\n" << endl;

        //this section will combine two strigs to give the players title
        cout << "Tell us your Name: " << endl;
        cin >> name;
        cout << "\n\t" << general + name << " We will have glorious victorys!\n" << endl;

        //this section will use the random number generator and add their age to it.
        cout << "Tell me you age." << endl;
        cin >> age;
        cout << "\tYour Warrior ID is: " << id + age << " Lose it and die!\n" << endl;

        //this just displays the players ship to them
        cout << "Your ship is called: " << destroyer.getName() << ".\nShe has seen manny battle, may she serve you well!\n" << endl;

        //this section will start the game
        cout << "If you are ready to prove your self! Hit'r' or 'R'\n" << endl;
        cin >> ready;

        //defines the counter for the loops to kill
        int attack = 1;

        while (true)
        {
            //show the numbers of loops to kill and opponent
            cout << "Attack " << attack << "\n" << endl;

            //determins the attacker and the reciver randomly using the value of determineAttacker random number
            if (determineAttacker())
            {
                cout << destroyer.getName() << " Is firering on enemy vessel!" << endl;
                escort.takeDamage(destroyer.fire());
                Sleep(2000);
            }
            else
            {
                cout << escort.getName() << " Is firering on " << destroyer.getName() << "!" << endl;
                destroyer.takeDamage(escort.fire());
                Sleep(2000);
            }

            //determins when a players hull strength is at zero
            if (escort.getHealth() <= 0)
            {
                cout << escort.getName() << " Glorious!  The enemy has been destroyed!" << endl;
                string winship = " USS Picard";
                string enemy = "Enemy";
                string winner = enemy + winship;

                WriteLineToFile(winner);
                break;
            }
            if (destroyer.getHealth() <= 0)
            {
                cout << destroyer.getName() << " has suffered a hull damage!  You are dead.  Today was a good day to die!" << endl;

                string winship = " IKS Chekuv";
                string player = captain + name;
                string winner = name + winship;
                WriteLineToFile(winner);
                break;
            }
            cout << destroyer.getName() << "'s hull is now at " << destroyer.getHealth() << "!" << endl;
            cout << escort.getName() << " 's hull is now at " << escort.getHealth() << "!\n" << endl;

            //update the simulation number
            attack++;
        }
    }
    else if (choice == 3)
    {
        cout << "\t\tView Scores\n" << endl;

        ifstream ifs("winners.txt");
        cout << ifs.rdbuf() << endl;
    }
}