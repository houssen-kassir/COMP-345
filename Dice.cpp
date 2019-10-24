
#include "Dice.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

Dice::Dice()
{
	//initializes the random number generator
	srand(time(0));
	result = value();
}

Dice::~Dice()
{
}

int Dice::value()
{
	//randomize result with a value between 1 and 6
	result = rand() % 6 + 1;
	return result;
}

int Dice::getResult() const
{
	return result;
}

DiceRoll::DiceRoll()
{
	//We initialize our values to 0
	
	totalRolls = 0;
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	num5 = 0;
	num6 = 0;
}


DiceRoll::~DiceRoll()
{
}

//For the percentages, we simply divide the number of times a value came up, divide by the total amount of rolls and multiply by 100
void DiceRoll::percentage()
{
	num1Per= num1/totalRolls*100;
	num2Per= num2/totalRolls*100;
	num3Per= num3/totalRolls*100;
	num4Per= num4/totalRolls*100;
	num5Per= num5/totalRolls*100;
	num6Per= num6/totalRolls*100;
}

int DiceRoll::roll(int numDice)
{
	//initialize the value of each dice to 0. The dice will then have the value of the roll (between 1 and 6)
	int dice1 = 0;
	int dice2 = 0;
	int dice3 = 0;


	//Here, we use a switch to determine how many dice will be rolled
	switch (numDice)
	{
	case 1:
		{
			cout<<"\nThe result of the roll was: ";
			dice1 = oDice.value();
			cout << dice1 << endl<<endl;
			totalRolls++; //Increment the total number of rolls by one. We keep track of this to calculate the percentages

			break;
		}
	case 2:
		{
			cout<<"\nThe results of the rolls were: ";
			dice1 = oDice.value();
			cout << dice1 << " ";
			totalRolls++;
			dice2 = oDice.value();
			cout << dice2 << endl<<endl;
			totalRolls++;

			break;
		}
	case 3:
		{
			cout<<"\nThe results of the rolls were: ";
			dice1 = oDice.value();
			cout << dice1 << " ";
			totalRolls++;
			dice2 = oDice.value();
			cout << dice2 << " ";
			totalRolls++;
			dice3 = oDice.value();
			cout << dice3 << endl<<endl;
			totalRolls++;

			break;
		}
		//The only accepted values are from 1 to 3. More than that, and the following error message appears.
	default:
		{
			cout << "\nYou have not selected a valid number." << endl<<endl;
		}
	}

	//When the rolls are done, the value of each dice is used to increment the number of times that specific number came up. Again, this is for percentages.
	switch (dice1)
	{
	case 1: {num1++;break;}
	case 2: {num2++;break;}
	case 3: {num3++;break;}
	case 4: {num4++;break;}
	case 5: {num5++;break;}
	case 6: {num6++;break;}
	default:{break;}
	}
	
	switch (dice2)
	{
	case 1: {num1++;break;}
	case 2: {num2++;break;}
	case 3: {num3++;break;}
	case 4: {num4++;break;}
	case 5: {num5++;break;}
	case 6: {num6++;break;}
	default:{break;}
	}
	switch (dice3)
	{
	case 1: {num1++;break;}
	case 2: {num2++;break;}
	case 3: {num3++;break;}
	case 4: {num4++;break;}
	case 5: {num5++; break;}
	case 6: {num6++; break;}
	default:{break;}
	}
	
	
	this->percentage(); //We create all percentages for the rolls that just happened
}



//Here, we print the percentage of each roll with the values from the percentage() method.
void DiceRoll::showRolls() const
{
	cout << fixed;
	cout << setprecision(2);
	cout << "Total number of rolls: " << totalRolls <<endl;
	cout << "Percentage of 1 obtained: " << num1Per << endl;
	cout << "Percentage of 2 obtained: " << num2Per << endl;
	cout << "Percentage of 3 obtained: " << num3Per << endl;
	cout << "Percentage of 4 obtained: " << num4Per << endl;
	cout << "Percentage of 5 obtained: " << num5Per << endl;
	cout << "Percentage of 6 obtained: " << num6Per << endl;
}
