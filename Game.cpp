#include "Game.h"

Game::Game()
{
	conPtr = GameBoard;
	load.LoadMap(conPtr);
}

Game::~Game()
{
}

void Game::handle_events(sf::RenderWindow & window, sf::Event & currEvent)
{
	while (window.pollEvent(currEvent))
	{
		switch (currEvent.type)
		{
		case sf::Event::KeyPressed:
			if (currEvent.key.code == sf::Keyboard::Escape)
			{
				setNextState(GameStates::EXIT);
			}
			break;
		}
	}
}

void Game::logic()
{
}

void Game::draw(sf::RenderWindow & window)
{
	
}
