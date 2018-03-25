#ifndef MAP_H
#define MAP_H

#include"GameMapTypeDef.h"
#include <iostream>
#include <string>

using namespace std;
const int MAX_COUNTRIES = 60;
const int MAX_BORDERS = 8;
const int MAX_CONT = 12;

class Country
{
private:

	string countryName;
	string borders[MAX_BORDERS];
	string contName;//Name of the Continet the country belongs to

	void setBorders();


public:

	int id;
	int armyValue;//Army value of current player on the country
	int borderPos;
	int xPos;
	int yPos;
	string playerName;//Name of current owner of the country

	//functions
	Country();
	Country(const Country&);
	Country(string);
	Country(int, int, int x, int y, string, string, string);
	int getArmyValue();
	int getBorderPos();
	int getPlayerId();
	int getCountryPositionX();
	int getCountryPositionY();
	void setArmyValue(int);
	void SetPlayer(string);
	void addBorder(string);
	void setPlayerID(int);
	string* getBorders();
	string getPlayer();
	string getCountryName();
};

class Continent
{
private:
	string continentName;
	int Added_Value;
	int countryPos;
public:
	Country countries[MAX_COUNTRIES];

	Continent();
	Continent(int, string);
	Country* getCountries();
	string getName();
	int getAddedValue();
	int getCountryPos();
	void addCountry(Country);
	void setCountry();


};
#endif