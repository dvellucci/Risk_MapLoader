#include "GameController.h"

GameController::GameController()
{
	Continent GameBoard[MAX_CONT];
	Continent* conPtr = GameBoard;
	load.LoadMap(conPtr);
	mainWindow.create(sf::VideoMode(load.getMapDimensions().width, load.getMapDimensions().height, 32), "Risk", sf::Style::Titlebar | sf::Style::Close);

}

GameController::~GameController()
{

}

void GameController::start()
{
	gameLoop();
}

void GameController::gameLoop()
{
	sf::Event currEvent;

	auto stateID = GameStates::PLAYING;
	m_currentState = new Game();

	while (mainWindow.isOpen())
	{
		m_currentState->handle_events(mainWindow, currEvent);

		//Do state logic
		m_currentState->logic();

		changeState();

		//Do state rendering
		mainWindow.clear();
		if (stateID == GameStates::PLAYING)
		{
			mainWindow.draw(load.getMapSprite(), sf::BlendNone);
		}
		else
		{
			m_currentState->draw(mainWindow);
		}		
		mainWindow.display();
	}
}

void GameController::changeState()
{
	auto nextState = m_currentState->getNextState();
	//If the state needs to be changed
	if (m_currentState->getNextState() != null)
	{
		//Delete the current state
		if (nextState != EXIT)
		{
			delete m_currentState;
		}

		//Change the state
		switch (nextState)
		{
		case INTRO:
			//m_currentState = new Intro();
			break;

		case MAIN_MENU:
			//m_currentState = new MainMenu();
			break;

		case PLAYING:
			m_currentState = new Game();
			break;

		case PAUSE:
			break;

		case EXIT:
			mainWindow.close();
			break;
		}

		//Change the current state ID
		m_currentState->setStateID(nextState);

		//NULL the next state ID
		nextState = null;
	}
}