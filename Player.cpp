#pragma once
#include "Player.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

//Default Contructor
Player::Player() {
	player_name = "Unassigned";
}
//Would destroy the player object, not yet implemented nor necessary 
Player::~Player()
{
	std::cout << this.get_player_name() + " is \"destroyed \"." << std:endl;
}
//Constructor for with a specified name
Player::Player(std::string playerName) {
	player_name = playerName;
}

//Functions to be added later
void Player::reinforce() {
	std::cout << get_player_name() + " reinforces." << std::endl;
}
void Player::attack() {
	std::cout << get_player_name() + " attacks." << std::endl;
}
void Player::fortify() {
	std::cout << get_player_name() + " fortifies." << std::endl;
}
//Getter functions
std::string Player::get_player_name() {
	return Player.player_name;
}
std::int Player::get_hand_size() {
	return hand.size();
}
std::int Player::get_number_of_owned_countries() {
	return owned_countries.size();
}

//Functions to create
void Player::view_hand() {
//Checks to see if there are any cards in hand, if not it prints that there are no cards in hand
//Could use hand.empty() instead of size == 0
	if (this.get_hand_size() == 0){
		std::cout << this.get_player_name() + " has no cards in hand." << std:endl;
	}
	else {
		std::cout << this.get_player_name() + " is currently holding these cards in hand: ";
		for (int = 0; i < this.hand.size(), i++) {
			std::cout << hand.at(i).countryOnCard + " " + hand.at(i).typeOfCard + ", ";
		}
		//Formatting the text output
		std::endl;
	}
}
//Simply adds the card to the hand vector
void Player::add_to_hand(Card card) {
	this.hand.push_back(card);
}
//Uses the diceroll object's function roll, it is seperate to keep the diceroll object private
void Player::roll_dice(int number_of_rolls)
{
	this.personal_dice.roll(number_of_rolls);
}
//Checks to see if a country is owned and if it isn't, it adds it to the player's country vector
void Player::assign_country(Country& country) {
	if (country.owned() == true) {
		std::cout << country.get_country_name() + " is already owned by " + country.get_owner().get_player_name() << std::endl;
	}
	else {
		owned_countries.push_back(country);
		country.set_owned(true,*this);
	}
}
//Checks to see if the country is in the player's country vector and if it is, it removes it by removed it from the vector and setting the country to unowned
void Player::remove_country(Country& country)
{
	//The index is set to -1 as it will never be a possible index in the vector
	int index = null;
	for (i = 0; i < this.get_number_of_owned_countries(); i++) {
		if (owned_countries.at(i) == &country) {
			index = i;
		}
	}
	if (index == null) {
		std::cout << "Country was not found to be owned by " + this.get_player_name() + ". Unable to remove a country that the player does not own." << std::endl;
	}
	else {
		//may need to be owned_countries.erase(owned_countries.begin() + index)
		owned_countries.erase(index);
		&country.set_owned(false, *this);
	}
}
//Checks to see if the country vector is empty, if it is, its print out an error message and if not it prints out the country names
void Player::print_countries_owned()
{
	if (this.get_number_of_owned_countries() == 0) {
		std::cout << this.get_player_name() + " owns no countries." << std:endl;
	}
	else {
		std::cout << this.get_player_name() + " currently owns these countries : ";
		for (int = 0; i < this.hand.size(), i++) {
			std::cout << owned_countries.at(i).get_country_name() ", ";
		}
		//Formatting the text output
		std::endl;
	}
}