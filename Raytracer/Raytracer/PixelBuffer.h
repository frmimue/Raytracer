#pragma once

#include <fstream>
#include <math.h>
#include <time.h>

#include "Color.h"

class PixelBuffer
{
public:
	Color*	pixelBuffer;
	int		xSize;
	int		ySize;
public:
	PixelBuffer(int, int);
	~PixelBuffer();
	void savePPM(char*);
	void randomize();
};

