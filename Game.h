#pragma once
#ifndef GAME_H
#define Game_H
#include "SFML_Includes.h"
#include "Map.h"
#include "Load.h"
#include <utility>
#include "GameState.h"

class Game : public GameState
{
public:
	Game();
	~Game();

	void handle_events(sf::RenderWindow& window, sf::Event& currEvent);
	void logic();
	void draw(sf::RenderWindow& window);
	int getMapWidth() { return load.getMapDimensions().width; }
	int getMapHeight() { return load.getMapDimensions().height; }

private:

	Load load;
	Continent GameBoard[MAX_CONT];
	Continent* conPtr;
};

#endif