
#include <fstream>
#include<map>
#include <iostream>
#include<regex>
#include <string>
#include <list>
#include <sstream>
#include <vector>
#include <unordered_map>
#include"Map.h"
#include "SFML_Includes.h"

#ifndef LOAD_H_
#define LOAD_H_

using namespace std;

const string LOAD_MAP_FILE = "World.map";
const int MAX_FIELD_NUMBER = 3;


class Load
{
public:
	Load();
	~Load();
	void LoadMap(Continent*); // Loads the entire map file
	void StoreGameTerritory(Continent*);
	void StoreGameContinent(Continent*);
	sf::FloatRect getMapDimensions();
	sf::Sprite getMapSprite();
	sf::Image getMapImage() { return mapImage; }
	sf::Texture getMapTexture() { return mapTexture; }

private:
	LoadedMap worldMap;  // Store the map content from the created file
	string field[MAX_FIELD_NUMBER];

	sf::Sprite mapSprite;
	sf::Texture mapTexture;
	sf::Image mapImage;
};

#endif