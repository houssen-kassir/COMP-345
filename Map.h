//
//  Map.h
//  A1
//
//  Created by Raffi Alan Bezirjian on 2019-10-10.
//  Copyright © 2019 Raffi Alan Bezirjian. All rights reserved.
//

#pragma once
#include <vector>
#include <string>
#include "Country.h"
#include "Continent.h"


class MapTemplate
{
public:
    std::string map_name;
    std::vector<std::string> country_names;
    std::vector<std::string> continent_names;
    std::vector < std::vector <int> > countries_adjacencies;        //First index = A country    Second index = its adjacencies
    std::vector<int> continent_of_country;
    std::vector<int> continent_bonus;
    std::vector< std::vector <int> > countries_in_continent;        //First index = A continent    Second index = the countries it contains
};


class Map
{
public:
    
    Map();
    ~Map();
    Map(std::string name);
    Map(MapTemplate mapTemplate);
    std::vector<Country*> getAllCountries() { return countries; }
    std::string getMapDirectory() { return mapDirectory; }
    
    void set_nOfCountries(int numberOfCountries) { nOfCountries = numberOfCountries; }
    void set_nOfContinents(int numberOfContinents) { nOfContinents = numberOfContinents; }
    
    void PrintAllCountryNames();
    void PrintAllContinentNames();
    void CheckContinentBonus();
    int test_map_components();
    
    int nbOfCountries();
    std::vector<Country*> getCountries();
    
private:
    std::string mapDirectory;
    std::vector<Country*> countries;
    std::vector<Continent> continents;
    unsigned int nOfCountries;
    unsigned int nOfContinents;
    
    //private methods
    void ReadContinents(std::string fileName, std::vector<std::string>& continentName, std::vector<int>& continentID, std::vector<int>& continentBonusValue);
    void CreateContinents(std::vector<std::string>& continentName, std::vector<int>& continentID, std::vector<int>& continentBonusValue);
    void CreateContinents(std::vector<std::string>& continentName, std::vector<int>& continentBonusValue);
    void ReadCountries(std::string fileName, std::vector<std::string>& countryName, std::vector<int>& countryID, std::vector<int>& containingContinentID,
                       std::vector < std::vector <int> >& connectedCountryID);
    void CreateCountries(std::vector<std::string>& countryName, std::vector<int>& containingContinentID);
    void AssignConnectedCountries(std::vector < std::vector <int> >& connectedCountryID);
    void AssignContainedCountries(std::vector<int>& containingContinentID);
    void Split(const std::string& fullString, char cSplitter, std::vector<std::string>& splitStrings);
};


