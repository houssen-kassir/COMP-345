/*
1. Read text file
2.Detect Continent header
3.Read line by line: first string input is the continent name and second is continent army value. Give ID value according to line (First continent has ID 1, etc.) Add these to Continent vector.
4.Detect Country header
5.Read line by line: first int is country ID. Following string is name. Following int is continent it belongs to. Following ints do not matter as they are coordinates.
6.Detect border header
7. First int is the country. Following int are the countries that country is adjacent to.


#pragma once


class MapLoader

{

public:

MapLoader();

    ~MapLoader();

void Save(MapTemplate mapTemplate, Constants::MapExtension mapExtension);

MapTemplate Load(std::string mapName);

};
