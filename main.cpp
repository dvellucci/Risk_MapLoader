#include "Map.h"
#include "Load.h"
#include "SFML_Includes.h"
#include "GameController.h"
#include <utility>

int main()
{
	//Load load;
	//Continent GameBoard[MAX_CONT];
	//Continent* conPtr = GameBoard;
	//load.LoadMap(conPtr);

	//sf::RenderWindow window(sf::VideoMode(load.getMapDimensions().width, load.getMapDimensions().height, 32), "Risk", sf::Style::Titlebar | sf::Style::Close);

	//while (window.isOpen())
	//{
	//	// check all the window's events that were triggered since the last iteration of the loop
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		// "close requested" event: we close the window
	//		if (event.type == sf::Event::Closed)
	//			window.close();

	//		if (event.type == sf::Event::MouseButtonReleased)
	//		{
	//			if (load.getMapSprite().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
	//			{
	//				int x = sf::Mouse::getPosition(window).x - load.getMapSprite().getPosition().x;
	//				int y = sf::Mouse::getPosition(window).y - load.getMapSprite().getPosition().y;
	//				int width = load.getMapSprite().getGlobalBounds().width;
	//				int height = load.getMapSprite().getGlobalBounds().height;
	//				sf::Color color = load.getMapImage().getPixel(x, y);
	//				int a = color.a;
	//			
	//				std::cout << a << conPtr[2].countries[2].getCountryName() << std::endl;
	//			}
	//		}
	//	}

	//	window.clear(sf::Color::White);
	//	window.draw(load.getMapSprite(), sf::BlendNone);
	//	window.display();

	//}
	GameController gameCtrl;
	gameCtrl.start();
	
	return 0;
}
