#pragma once
#include <vector>
#include <string>



class Country{
	public:
		int getId();
		std::string getName();
		int getArmies();
		
		Country();
		Country(int nb, std::string call, int contID);
		
		
	private:
		int id;
		std::string name;
		int nbArmies;
		std::vector <int> edges;
		int continentID;
		bool isOwned;
		//Player player;
		
		
};

class Continent{
	public:
		int getId();
		std::string getName();
		int getArmy();
		
		Continent();
		Continent(int nb, std::string call, int arm);
		
	private:
		int id;
		int army;
		std::string name;
		std::vector <Country> listCountries;
	
};

class Map{
	public:
		
	private:
		std::vector <Continent> listContinent;
	
	
};

