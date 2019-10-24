#pragma once


#include <string>


using namespace std;


enum cardType {

infantry,

artillery,

cavalry,

};


class Card {


private:

string countryOnCard;

cardType typeOfCard;


public: 

Card(string country, cardType type);

string getCountryOnCard() {

}

cardType getTypeOfCard() {

}

};
