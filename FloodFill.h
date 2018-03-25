#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include "SFML_Includes.h"
#include "Load.h"

class FloodFill
{
public:
	FloodFill();
	~FloodFill();

	void floodFill4(uint32_t screenBuffer, int w, int h,
		int x, int y, int newColor, int oldColor);
	bool paint_drawLine(int x1, int y1, int x2, int y2, sf::Color color);
	void clearScreenBuffer(sf::Color color);

private:
//	std::vector<uint32_t> screenBuffer(screenH * screenW);
};