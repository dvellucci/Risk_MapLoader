#include "Map.h"
#include "Load.h"
#include "SFML_Includes.h"
#include <utility>
#include <set>
#include <queue>

void getCountryPointUtil(int x, int y, sf::Image& image, Continent* conPtr, Load& load, sf::Color currColor, int width, int height);
void getCountryPoint(int x, int y, sf::Image& image, Continent* conPtr, Load& load, sf::Color currColor);
void floodFill(int x, int y, sf::Image& image, sf::Color oldColor, sf::Color newColor);

int main()
{
	Load load;
	Continent GameBoard[MAX_CONT];
	Continent* conPtr = GameBoard;
	load.LoadMap(conPtr);

	sf::RenderWindow window(sf::VideoMode(load.getMapDimensions().width, load.getMapDimensions().height, 32), "Risk", sf::Style::Titlebar | sf::Style::Close);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (load.getMapSprite().getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
				{
					int x = sf::Mouse::getPosition(window).x - load.getMapSprite().getPosition().x;
					int y = sf::Mouse::getPosition(window).y - load.getMapSprite().getPosition().y;
					int width = load.getMapSprite().getGlobalBounds().width;
					int height = load.getMapSprite().getGlobalBounds().height;
					sf::Color color = load.getMapImage().getPixel(x, y);
					int a = color.a;
				
					std::cout << a << std::endl;
					//getCountryPointUtil(x, y, load.getMapImage(), conPtr, load, sf::Color::Red, width, height);
				}
			}
		}

		window.clear(sf::Color::White);
		window.draw(load.getMapSprite(), sf::BlendNone);
		window.display();

	}
	
	return 0;
}

void floodFill(int x, int y, sf::Image& image, sf::Color oldColor, sf::Color newColor)
{
	if (image.getPixel(x, y) == oldColor)
	{
		image.setPixel(x, y, newColor);
		floodFill(x + 1, y, image, oldColor, newColor);
		floodFill(x , y+1, image, oldColor, newColor);
		floodFill(x -1, y, image, oldColor, newColor);
		floodFill(x , y-1, image, oldColor, newColor);
	}
}

void getCountryPointUtil(int x, int y, sf::Image& image, Continent* conPtr, Load& load, sf::Color currColor, int width, int height)
{
	std::queue<pair<int, int>> q;
	std::set<pair<int, int>> prevPoints;
	set<pair<int, int>>::iterator setIter;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		std::pair<int, int> next = q.front();
		int x1 = next.first;
		int y1 = next.second;
		q.pop();
	
		for (int i = 0; i < MAX_CONT; i++)
		{
			for (int j = 0; j < MAX_COUNTRIES; j++)
			{
				if (x1 == conPtr[i].countries[j].getCountryPositionX() &&
					y1 == conPtr[i].countries[j].getCountryPositionY())
				{
					std::cout << conPtr[i].countries[j].getCountryName() << std::endl;
					return;
				}
			}
		}

		if (load.getMapImage().getPixel(x1 + 1, y1) == sf::Color::White && (prevPoints.find(make_pair(x1 + 1, y1)) == prevPoints.end()))
		{
			q.push(make_pair(x1 + 1, y1) );
			prevPoints.insert(make_pair(x1 + 1, y1));
		}		
		if (load.getMapImage().getPixel(x1, y1 + 1) == sf::Color::White && (prevPoints.find(make_pair(x1, y1+1)) == prevPoints.end()))
		{
			q.push(make_pair(x1, y1 + 1));
			prevPoints.insert(make_pair(x1, y1 + 1));
		}
		if (load.getMapImage().getPixel(x1 - 1, y1) == sf::Color::White && (prevPoints.find(make_pair(x1-1, y1)) == prevPoints.end()))
		{
			q.push(make_pair(x1 - 1, y1));
			prevPoints.insert(make_pair(x1 - 1, y1));
		}
		if (load.getMapImage().getPixel(x1, y1 - 1) == sf::Color::White && (prevPoints.find(make_pair(x1, y1-1)) == prevPoints.end()))
		{
			q.push(make_pair(x1, y1 - 1));
			prevPoints.insert(make_pair(x1, y1 - 1));
		}
		if (load.getMapImage().getPixel(x1 + 1, y1 + 1) == sf::Color::White && (prevPoints.find(make_pair(x1 + 1, y1 + 1)) == prevPoints.end()))
		{
			q.push(make_pair(x1 + 1, y1 + 1));
			prevPoints.insert(make_pair(x1 + 1, y1 + 1));
		}	
		if (load.getMapImage().getPixel(x1 + 1, y1 - 1) == sf::Color::White && (prevPoints.find(make_pair(x1 + 1, y1 - 1)) == prevPoints.end()))
		{
			q.push(make_pair(x1 + 1, y1 - 1));
			prevPoints.insert(make_pair(x1 + 1, y1 - 1));
		}	
		if (load.getMapImage().getPixel(x1 - 1, y1 + 1) == sf::Color::White && (prevPoints.find(make_pair(x1 - 1, y1 + 1)) == prevPoints.end()))
		{
			q.push(make_pair(x1 - 1, y1 + 1));
			prevPoints.insert(make_pair(x1 - 1, y1 + 1));
		}	
		if (load.getMapImage().getPixel(x1 - 1, y1 - 1) == sf::Color::White && (prevPoints.find(make_pair(x1 - 1, y1 - 1)) == prevPoints.end()))
		{
			q.push(make_pair(x1 - 1, y1 - 1));
			prevPoints.insert(make_pair(x1 - 1, y1 - 1));
		}			
	}

	std::cout << " country not found" << std::endl;
}
