#include "Load.h"

Load::Load()
{
	if (!mapTexture.loadFromFile("World.bmp"))
	{
		// error...
	}

	mapSprite.setTexture(mapTexture);
	mapImage = mapTexture.copyToImage();
	
}

Load::~Load()
{
}

void Load::LoadMap(Continent* conPTR)
{
	regex regKey("^\\[", regex_constants::icase); // Indentifies when a category is found
	int numberOfField = -1;           // Keeps tracks of the number of found in the file
	string readLine, insertInMap = ""; // Store the content of the one line at the time
	ifstream  fInput;                 // Needed to read and load the file's content

	fInput.open(LOAD_MAP_FILE, ios_base::in);

	// Loop untill each line of the text file is read
	while (true)
	{
		if (fInput.eof()) // If the end of file is reached close the file
		{
			fInput.close(); // The is no longer needed
			break;
		}

		std::getline(fInput, readLine);   // Grabs line in the file one by one

		if (std::regex_search(readLine, regKey)) // Looks for key field
		{
			numberOfField++;
			field[numberOfField] = readLine.substr(1, readLine.length() - 2); // Strores the different categories
		}
		else
		{
			insertInMap = field[numberOfField];
			worldMap.insert(pair<string, string>(insertInMap, readLine)); // Inserts the category and all lines associated to category 
		}
	}

	//Stores the values from the files into memory
	StoreGameContinent(conPTR);
	StoreGameTerritory(conPTR);
}

void Load::StoreGameTerritory(Continent* conPTR)
{//Store all the territory information found form the loaded map

	MapIterator it, it2;
	string delimiter = ",";
	string token, name;
	int x, y;
	string con;
	size_t pos = 0;
	int continentCount = 0, countryCount = 0, ajdCount = 0;  // Counters to store in the gameboard
	int stringIndex = 1; // position of the string when parsing

	it = worldMap.lower_bound(field[2]);  // upper bound of search 
	it2 = worldMap.end(); //Lower bound of search

	// Parse and store the values found
	// from the loaded map line by line
	while (it != it2)
	{
		if (it->second != "") // Skips empty lines
		{
			while ((pos = it->second.find(delimiter)) != string::npos)
			{
				token = it->second.substr(0, pos);

				switch (stringIndex)
				{
				case 1:
					name = token; break;    // country found
				case 2:
					x = stoi(token); break; // x coordinate found
				case 3:
					y = stoi(token); break; // y coordinate found
				case 4:
					con = token;  break;    // continent found
				default:
					if (ajdCount == 0)
						conPTR[continentCount].addCountry(Country(0, 0, x, y, "", name, con));

					conPTR[continentCount].countries[countryCount].addBorder(token);
					ajdCount++; // index to the next adjacent country
					break; // Adjacent terrytory found

				}

				stringIndex++;
				it->second.erase(0, pos + delimiter.length());
			}
			// Stores the last found value
			token = it->second.substr(0, pos);
			conPTR[continentCount].countries[countryCount].addBorder(token);
			it->second.erase(0, pos + delimiter.length());

			// Store the countries information in a list
			ajdCount = 0;
			stringIndex = 1; // Reset index
			countryCount++;  // index to the next country
			it++;  // Go to the nex line
		}
		else
		{
			continentCount++; // index to the next continent
			it++; // Go to the next line
		}
	}
}

void Load::StoreGameContinent(Continent* conPTR)
{// Stores the all the continents found in the loaded map

	MapIterator it, it2;
	string delimiter = "="; // Delimiter for parsing
	string token;
	int countContinent = 0;
	size_t pos = 0;
	string conName;
	int conVal;

	it = worldMap.lower_bound(field[1]); // search for upper bound
	it2 = worldMap.upper_bound(field[1]); // search for lower bound

	// Parse and store the values found
	// from the loaded map line by line
	while (it != it2)
	{
		if (it->second != "")
		{
			pos = it->second.find(delimiter);
			token = it->second.substr(0, pos);
			conName = token;   // Store the continent's name
			it->second.erase(0, pos + delimiter.length());

			token = it->second;
			conVal = stoi(token); // Store the continent value
			it->second.erase(0, pos + delimiter.length());

			//Store the found information inside list
			conPTR[countContinent] = Continent(conVal, conName);

			countContinent++;

		}
		it++; // Go to the next line
	}
}

sf::FloatRect Load::getMapDimensions()
{
	return mapSprite.getGlobalBounds();
}

sf::Sprite Load::getMapSprite()
{
	return mapSprite;
}