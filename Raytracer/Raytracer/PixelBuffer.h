#pragma once

#include <fstream>

#include "Color.h"

class PixelBuffer
{
private:
	Color*	pixelBuffer;
	int		xSize;
	int		ySize;
public:
	PixelBuffer(int, int);
	~PixelBuffer();
	void savePPM(char*);
};

