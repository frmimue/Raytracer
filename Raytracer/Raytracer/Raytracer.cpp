#include "PixelBuffer.h"

int main(int argv, char** argc){
	PixelBuffer* pixelBuffer = new PixelBuffer(1920, 1080);
	pixelBuffer->randomize();
	pixelBuffer->savePPM("123.ppm");
	return 0;
}