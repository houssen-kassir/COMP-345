#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "Country.h"
#include "Deck.h"
#include "Strategy.h"
#include "Map.h"
#include "Card.h"
#include "Dice.h"

class Player
{
private:
	//Getter functions have been implemented for these private variables
	std::string player_name;
	std::vector<Card> hand;
	std::vector<Country*> owned_countries; header
	Diceroll personal_dice;
public:
	//Constructors
	Player();
	Player(std::string Name);
	//Destructor
	~Player();
	//Three functions that will be implemented later
	void reinforce();
	void attack();
	void fortify();
	//Country manipulation functions
	void assign_country(Country& country);
	void remove_country(Country& country);
	void print_countries_owned();
	//Hand manipulation functions
	void view_hand();
	void add_to_hand(Card card);
	//Roll dice
	void roll_dice(int number_of_rolls);

};




