#pragma once


#include <string>


using namespace std;


enum cardType {Infantry, Cannon, Cavalry};


class Card {


private:

int countryOnCard;

cardType typeOfCard;


public: 

Card(int country, cardType type);

int getCountryOnCard() {

}

cardType getTypeOfCard() {

}

};
