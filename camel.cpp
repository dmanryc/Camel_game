/*
Author: David Manry
Created: 01 May 2017
Class: ITSE 2421 - Object Oriented Programming
Instructor: Prof  Welch
Problem description: Create the Camel game.

Todo - Summary of Modifications:
04/27/2017 - Created main and menu functions.
04/28/2017 - Created rest of functions.
04/29/2017 - Error checking and rewrite program.
04/30/2017 - Error checking and testing.
05/01/2017 - Error checking, testing, and completion.

Lessons learned:
(1) I relearned the difference between the '=' operator and the '==' operator. After two days of tedious checking and rechecking and rewriting and intense frustration, a classmate noticed i used the '=' operator	in my while loop instead of the '==' operator.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

void printWelcome();
void printMenu();
char choice();
void drink(int *valTh, int *valD);
void modSpeed(int *valTr, int *valTh, int *valCT, int *valNT);
void fullSpeed(int *valTr, int *valTh, int *valCT, int *valNT);
void stop(int *valCT, int *valNT);
void status(int *valTr, int *valD, int *valNT);
bool isValid(char selection);
void findOasis(int *valTh, int *valCT, int *valD);
void updates(int *valTr, int *valTh, int *valCT, int *valNT);
bool endGame(int *valTr, int *valTh, int *valCT, int *valNT);

ofstream fout;

int main()
{
	fout.open("results.txt");

	srand(time(0));

	printWelcome();

	cout << "A.  Drink from your canteen." << endl;
	cout << "B.  Ahead moderate speed." << endl;
	cout << "C.  Ahead full speed." << endl;
	cout << "D.  Stop for the night." << endl;
	cout << "E.  Status check." << endl;
	cout << "Q.  Quit." << endl;

	fout << "A.  Drink from your canteen." << endl;
	fout << "B.  Ahead moderate speed." << endl;
	fout << "C.  Ahead full speed." << endl;
	fout << "D.  Stop for the night." << endl;
	fout << "E.  Status check." << endl;
	fout << "Q.  Quit." << endl;

	int mtrv = 0;
	int thst = 0;
	int ctired = 0;
	int ntrav = -20;
	int ndrk = 3;
	char ch;
	bool done = false;

	do
	{
		ch = choice();

		switch (ch)
		{
		case 'a':
		case 'A': drink(&thst, &ndrk);
			updates(&mtrv, &thst, &ctired, &ntrav);
			if (endGame(&mtrv, &thst, &ctired, &ntrav) == true)
			{
				done = true;
			}
			break;
		case 'b':
		case 'B': modSpeed(&mtrv, &thst, &ctired, &ntrav);
			findOasis(&thst, &ctired, &ndrk);
			updates(&mtrv, &thst, &ctired, &ntrav);
			if (endGame(&mtrv, &thst, &ctired, &ntrav) == true)
			{
				done = true;
			}
			break;
		case 'c':
		case 'C': fullSpeed(&mtrv, &thst, &ctired, &ntrav);
			findOasis(&thst, &ctired, &ndrk);
			updates(&mtrv, &thst, &ctired, &ntrav);
			if (endGame(&mtrv, &thst, &ctired, &ntrav) == true)
			{
				done = true;
			}
			break;
		case 'd':
		case 'D': stop(&ctired, &ntrav);
			updates(&mtrv, &thst, &ctired, &ntrav);
			if (endGame(&mtrv, &thst, &ctired, &ntrav) == true)
			{
				done = true;
			}
			break;
		case 'e':
		case 'E': status(&mtrv, &ndrk, &ntrav);
			break;
		case 'q':
		case 'Q': done = true;
			break;
		}
	} while (done == false);

	fout.close();
    return 0; 
}

//******************************************************************************

void printWelcome()
{
	cout << "Welcome to Camel!" << endl;
	cout << "You have stolen a camel to make your way across the great Mobi desert. " << endl
		<< "The natives want their camel back and are chasing you down! Survive your " << endl
		<< "desert trek and out run the natives." << endl;

	fout << "Welcome to Camel!" << endl;
	fout << "You have stolen a camel to make your way across the great Mobi desert. " << endl
		<< "The natives want their camel back and are chasing you down! Survive your " << endl
		<< "desert trek and out run the natives." << endl;

}// end printMenu()

void printMenu()
{
	
}// end void printMenu()

char choice()
{
	char choice;

	cout << "Your choice? ";
	fout << "Your choice? ";
	cin >> choice;
	cout << endl;

	//loops until user choice is valid. passes choice to bool function which returns false if
	// user choice is diff than selection and true if its valid.
	while (isValid(choice) == false)
	{
		cout << "Invalid entry. Please try again." << endl;
		fout << "Invalid entry. Please try again." << endl;
		cin >> choice;
	 }

	return choice;

}// end char choice()

void status(int *valTr, int *valD, int *valNT)
{
	cout << "       Current Status" << endl;
	cout << "Miles Traveled: " << *valTr << endl;
	cout << "Drinks in Canteen: " << *valD << endl;
	cout << "The natives are " << abs(*valTr - abs(*valNT)) << " miles behind you." << endl;

	fout << "       Current Status" << endl;
	fout << "Miles Traveled: " << *valTr << endl;
	fout << "Drinks in Canteen: " << *valD << endl;
	fout << "The natives are " << abs(*valTr - abs(*valNT)) << " miles behind you." << endl;

}// end void status()

bool isValid(char selection)
{
	//bool function to determine if user selection is valid.
	bool validChar = false;
	if (selection == 'A' || selection == 'a')
	{
		return validChar = true;
	}
	else if (selection == 'B' || selection == 'b')
	{
		return validChar = true;
	}
	else if (selection == 'C' || selection == 'c')
	{
		return validChar = true;
	}
	else if (selection == 'D' || selection == 'd')
	{
		return validChar = true;
	}
	else if (selection == 'E' || selection == 'e')
	{
		return validChar = true;
	}
	else if (selection == 'Q' || selection == 'q')
	{
		return validChar = true;
	}
	else
	{
		return validChar;
	}
}// end bool isValid()

void stop(int *valCT, int *valNT)
{
	int minN = 7;
	int maxN = 14;
	*valCT = 0;
	*valNT += (rand() % (maxN - minN + 1) + minN);
	cout << "The camel is fully rested." << endl;
	fout << "The camel is fully rested." << endl;

}// end stop()

//increase thirst variable by one and use rand num to update users miles traveled,
// camels tiredness, and how far natives have traveled.
void fullSpeed(int *valTr, int *valTh, int *valCT, int *valNT)
{
	int minTr = 10;
	int maxTr = 20;
	int minC = 1;
	int maxC = 3;
	int minN = 7;
	int maxN = 14;

	*valTh += 1;

	*valTr += (rand() % (maxTr - minTr + 1) + minTr);

	*valCT += (rand() % (maxC - minC + 1) + minC);

	*valNT += (rand() % (maxN - minN + 1) + minN);

	cout << "You traveled " << *valTr << " miles." << endl;
	fout << "You traveled " << *valTr << " miles." << endl;
	
}// end void fullSpeed()

//does the same as the full speed function, just using smaller numbers.
void modSpeed(int *valTr, int *valTh, int *valCT, int *valNT)
{
	int minTr = 5;
	int maxTr = 12;
	int minC = 1;
	int maxC = 1;
	int minN = 7;
	int maxN = 14;

	*valTh += 1;

	*valTr += (rand() % (maxTr - minTr + 1) + minTr);

	*valCT += (rand() % (maxC - minC + 1) + minC);

	*valNT += (rand() % (maxN - minN + 1) + minN);

	cout << "You traveled " << *valTr << " miles." << endl;
	fout << "You traveled " << *valTr << " miles." << endl;

}// end void modSpeed()

//subtracts one drink from canteen each time function is called and resets thirst to 0.
void drink(int *valTh, int *valD)
{
	if (*valD > 0)
	{
		*valTh = 0;
		*valD -= 1;
	}
	else
	{
		cout << "You have no drinks in your canteen.";
		fout << "You have no drinks in your canteen.";
	}
	
}// end void drink()

void findOasis(int *valTh, int *valCT, int *valD)
{
	int oasis;

	oasis = (rand() % (20 - 1 + 1) - 1);

	if (oasis == 13)
	{
		cout << "You got lucky and found an oasis! You and the camel were able to rest " <<
			"and you were able to refill your canteen." << endl;

		fout << "You got lucky and found an oasis! You and the camel were able to rest " <<
			"and you were able to refill your canteen." << endl;

		*valTh = 0;
		*valCT = 0;
		*valD = 3;
	}
}// end void oasis()

void updates(int *valTr, int *valTh, int *valCT, int *valNT)
{
	if (*valTh > 4 && *valTh <=6)
	{
		cout << "You are thristy." << endl;
		fout << "You are thristy." << endl;
	}

	if (*valCT > 5 && *valCT <= 8)
	{
		cout << "Your camel is getting tired." << endl;
		fout << "Your camel is getting tired." << endl;
	}

	if ((*valTr - abs(*valNT)) <= abs(15))
	{
		cout << "The natives are getting close!" << endl;
		fout << "The natives are getting close!" << endl;
	}
}// end void updates();

bool endGame(int *valTr, int *valTh, int *valCT, int *valNT)
{
	bool end = false;

		if (*valTh > 6)
		{
			cout << "You died of thirst." << endl;
			fout << "You died of thirst." << endl;
			end = true;
		}
		if (*valCT > 8)
		{
			cout << "Your camel died." << endl;
			fout << "Your camel died." << endl;
			end = true;
		}
		if (*valTr == *valNT)
		{
			cout << "The natives have caught you!" << endl;
			fout << "The natives have caught you!" << endl;
			end = true;
		}
		if (*valTr >= 200)
		{
			cout << "Congratulations! You made it across the desert!" << endl;
			fout << "Congratulations! You made it across the desert!" << endl;
			end = true;
		}
	
	return end;
}// end bool endGame()
