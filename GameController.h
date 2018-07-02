#pragma once
#ifndef Game_H
#define Game_H
#include "GameState.h"
#include "GameStates.h"
#include "Map.h"
#include "Load.h"
#include <utility>
#include "Game.h"


class GameController
{
public:
	GameController();
	~GameController();

	void start();
	void gameLoop();
	void changeState();

private:

	sf::RenderWindow mainWindow;
	//Game state object
	GameState *m_currentState;
	Load load;

};

#endif