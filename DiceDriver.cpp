#include "Dice.h"
#include <iostream>
#include "DiceDriver.h"

DiceDriver::DiceDriver()
{
}

DiceDriver::~DiceDriver()
{
}


void DiceDriver::demo()
{
	int x;
	DiceRoll a; //creates a DiceRoll object
	std::cout<<"Choose the number of dice you wish to roll: ";
	std::cin>> x;
	for (int i = 0; i < 50; i++) //For the demo, we looped the rolls 50 times, along with the percentage prints. 
	{
		a.roll(x); 
		
		a.showRolls(); 
	}
}

int main(){
	
	DiceDriver a; //Our first rolling facility
	a.demo();
	
	DiceDriver b; //Our second rolling facility
	b.demo();
	
}
