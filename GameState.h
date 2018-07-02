#pragma once
#pragma once
#ifndef GameState_H
#define GameState_H
#include "SFML_Includes.h"
#include "GameStates.h"

class GameState
{
public:
	virtual ~GameState() {};
	virtual void handle_events(sf::RenderWindow& window, sf::Event& currEvent) = 0;
	virtual void logic() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	//State status manager
	void setNextState(int newState)
	{
		//If the user doesn't want to exit
		if (nextState != EXIT)
		{
			//Set the next state
			nextState = newState;
		}
	};

	void setStateID(int stateID)
	{
		this->stateID = stateID;
	}

	const int getNextState() { return nextState; }
	const int getCurrentState() { return stateID; };

private:

	//State variables
	int stateID = null;
	int nextState = null;

	bool close = false;

};

#endif