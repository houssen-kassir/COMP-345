//
//  Driver.cpp
//  A1
//
//  Created by Raffi Alan Bezirjian on 2019-10-10.
//  Copyright © 2019 Raffi Alan Bezirjian. All rights reserved.
//
#include "Country.h"
//#include "Deck.h"
#include "Player.h"
#include <stdio.h>
#include <iostream>
#include <string>

void player_testing() {
	Player p1("Raffi");
}
void country_testing() {
	Player p1("David");
	std::cout << p1.get_player_name() + " currently owns: " + p1.print_countries_owned() << std::endl;

	Country c1("Canada");
	Country c2("USA");
	Country c3("Mexico");

	p1.assign_country(c1);
	p1.assign_country(c2);
	p1.assign_country(c3);

	Player p2("Tylor");
	p2.assign_country(c1);
	p2.remove_country(c1);

	p1.remove_country(c1);
	p2.assign_country(c1);

	std::cout << p1.get_player_name() + " currently owns: " + p1.print_countries_owned() << std::endl;
	std::cout << p2.get_player_name() + " currently owns: " + p2.print_countries_owned() << std::endl;
}

void card_testing() {
	Player p1("Houssein");
	Deck deck;
	Deck::Card card0;
	card0.card_id = 3;
	deck.return_card(card0);
	Deck::Card card1 = deck.draw_card();
	deck.return_card(card1);
	p1.view_hand();
	p1.add_to_hand(deck.draw_card());
	p1.add_to_hand(deck.draw_card());
	p1.view_hand();
}
void action_testing() {
	Player p1("Houssein");
	p1.fortify();
	p1.attack();
	p1.reinforce();
	p1.roll_dice(2);
}

int main(){
	
	card_testing();
	action_testing();
	
	
}
