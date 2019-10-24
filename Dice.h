#pragma once


class Dice 
{
public:
	Dice();
	~Dice();
	int value(); //function to roll a random number between 1 and 6
	int getResult() const; 

private:
	int result; 
};

class DiceRoll
{
public:
	DiceRoll();
	~DiceRoll();
	void percentage(); //calculates the percentage of each roll
	int roll(int numDice); //rolls between 1 and 3 dice
	void showRolls() const; //print total number of rolls and each percentage
	

private:
	Dice oDice;
	int totalRolls;
	float num1;
	float num2;
	float num3;
	float num4;
	float num5;
	float num6;
	float num1Per;
	float num2Per;
	float num3Per;
	float num4Per;
	float num5Per;
	float num6Per;
	

};
