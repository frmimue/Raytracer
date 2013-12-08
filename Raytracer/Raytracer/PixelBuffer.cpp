#include "PixelBuffer.h"


PixelBuffer::PixelBuffer(int Xsize, int Ysize)
{
	this->pixelBuffer = new Color[Xsize*Ysize];
	this->xSize = Xsize;
	this->ySize = Ysize;
}


PixelBuffer::~PixelBuffer()
{
	delete[] pixelBuffer;
}

void PixelBuffer::randomize(){
	srand(time(NULL));
	for (int i = 0; i < xSize*ySize; i++){
		pixelBuffer[i].red = rand() % 255;
		pixelBuffer[i].green = rand() % 255;
		pixelBuffer[i].blue = rand() % 255;
	}
}


void PixelBuffer::savePPM(char* file){
	std::ofstream data;
	data.open(file);
	data << "P3" << " " << xSize << " " << ySize << " " << "255" << " ";
	for (int i = 0; i < xSize*ySize; i++){
		data << pixelBuffer[i].red << " " << pixelBuffer[i].green << " " << pixelBuffer[i].blue << " ";
	}
	data.close();
}


void PixelBuffer::set(int x, int y, Color color){
	pixelBuffer[x*ySize + y].red = color.red;
	pixelBuffer[x*ySize + y].green = color.green;
	pixelBuffer[x*ySize + y].blue = color.blue;
}
