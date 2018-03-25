#include "Map.h"

Country::Country(const Country& copyCont)
{//Country Copy-Constructor
	armyValue = copyCont.armyValue;
	countryName = copyCont.countryName;
	playerName = copyCont.playerName;
	contName = copyCont.contName;
	borderPos = copyCont.borderPos;
	xPos = copyCont.xPos;
	yPos = copyCont.yPos;

	for (int i = 0; i < borderPos; i++)
		borders[i] = copyCont.borders[i];

}

Country::Country(int playedID, int Val, int x, int y, string player, string name, string Con)
{//Country Constructor 
	id = playedID;
	armyValue = Val;
	xPos = x;
	yPos = y;
	countryName = name;
	playerName = player;
	contName = Con;
	borderPos = 0;

	setBorders();
}

Country::Country(string name)
{//Country default constructor
	//armyValue = 100;
	countryName = name;
	borderPos = 0;

	setBorders();

}

Country::Country()
{
	//countryName = "HEllo";
	borderPos = 0;
	setBorders();

}

void Country::setBorders()
{//Initialize Borders to empty strings
	for (int i = 0; i < MAX_BORDERS; i++)
		borders[i] = "";
}

int Country::getCountryPositionX()
{
	return xPos;
}

int Country::getCountryPositionY()
{
	return yPos;
}


int Country::getArmyValue()
{//Gets Players army value on country
	return armyValue;
}

int Country::getBorderPos()
{//Gets position of last border populated in the array
	return borderPos;
}

string Country::getPlayer()
{//Gets Player name name who owns the country
	return playerName;
}

int Country::getPlayerId()
{
	return id;
}

void Country::SetPlayer(string name)
{//Sets owner of country 
	playerName = name;
}

void Country::addBorder(string borderName)
{//Adds a border to a country
	borders[borderPos++] = borderName;
}

void Country::setArmyValue(int Val)
{//Sets the players current armyvalue of the country
	armyValue = Val;
}

string Country::getCountryName()
{//returns the name the country
	return countryName;
}

string* Country::getBorders()
{//returns a pointer to the array of borders surrounding the country
	return borders;
}

Continent::Continent()
{//default Continent constructor
	continentName = "HELLO";
	countryPos = 0;
	Added_Value = 0;
}

Continent::Continent(int Val, string place)
{//Continet constructor 
	countryPos = 0;
	Added_Value = Val;
	continentName = place;
}

Country* Continent::getCountries()
{//returns a pointer to the array of countries within the continent
	return countries;
}

string Continent::getName()
{//returns name of the continent
	return continentName;
}

int Continent::getAddedValue()
{//returns the continents added army value 
	return Added_Value;
}

int Continent::getCountryPos()
{//gets the position of the last country added to the continent
	return countryPos;
}

void Continent::addCountry(Country theCont)
{//Adds a country to the continent
	Country a = theCont;
	countries[countryPos++] = a;
}

void Country::setPlayerID(int playerId)
{
	id = playerId;
}