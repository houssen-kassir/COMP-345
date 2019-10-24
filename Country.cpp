#include <iostream>

#include <string>


#include "Country.h"

#include "Player.h" 




Country::Country(std::string name) {

country_name = name;   // string representing country name

continent_name = "";

//Initialized to NULL as when the country is created, it does not have an owner.

owner = NULL; // pointer to the player that currently owns the country

containing_continent = NULL;

//Initialized to false as when the country is created, it does not have an owner.

is_owned = false; // boolean representing if country is currently owned

number_of_armies = 0; // representing number of armies situated in this country

//std::cout << get_country_name() + " Country object created." << std::endl;

}



Country::~Country() {

//std::cout << get_country_name() + " Country object destroyed." << std::endl;

}


Country::Country(const Country &anotherCountry) {

country_name = anotherCountry.country_name;

continent_name = anotherCountry.continent_name;

owner = anotherCountry.owner;

containing_continent = anotherCountry.containing_continent;

is_owned = anotherCountry.is_owned;

number_of_armies = anotherCountry.number_of_armies;

}


void Country::set_continent_name(std::string c_name) {

continent_name = c_name;

notifyObservers();

}


std::string Country::get_country_name() {

return country_name;

}


std::string Country::get_continent_name() {

return continent_name;

}


void Country::set_owned(bool value, Player& player) {

//If value is true, then we can assign the address of the player to the Player pointer, owner.

if(value == true) {

is_owned = value;

owner = &player;

notifyObservers();


}

//Else, set the Player pointer, owner back to NULL.

else {

is_owned = value;

owner = NULL;

}

}


Player* Country::get_owner() {

return owner;

}


std::string Country::get_owner_name() {

//If the Player pointer, owner is currently set to NULL, inform the system that the country has no owner.

if(owner == NULL) {

return "This country has no owner!";

}

//Else, through the Player pointer, owner, retrieve the string value of the player's name.

else {

return owner->get_player_name();

}

}


bool Country::owned() {

return is_owned;

}


void Country::increment_armies(int amt) {

number_of_armies += amt;

notifyObservers();

//owner->Notify();

}


void Country::decrement_armies(int amt) {

//If the decrement will reduce the number of armies situated in the country to below 0, inform the system.

if((number_of_armies - amt) < 0) {

std::cout << "Invalid decrement. Cannot decrease the number of armies below 0" << std::endl;

}

//Else, decrement the number of armies by amt.

else {

number_of_armies -= amt;

notifyObservers();


}

}


int Country::get_number_of_armies() {

return number_of_armies;

}


void Country::notifyObservers() {

for (unsigned int i = 0; i < observers.size(); i++) {

observers.at(i)->update(this);

}

}


void Country::printConnectedCountries() {

for (Country* c : connectedCountries) {

cout << c->get_country_name() << endl;

}

}

