#include "PixelBuffer.h"

#include <math.h>

PixelBuffer::PixelBuffer(int Xsize, int Ysize) {
    this->pixelBuffer = new Color[Xsize * Ysize];
    this->xSize = Xsize;
    this->ySize = Ysize;
}


PixelBuffer::~PixelBuffer() {
    delete[] pixelBuffer;
}


void PixelBuffer::savePPM(std::string file) {
	FILE *pFile = fopen(file.c_str(), "wb");

	char header[255];

	int count = sprintf(header, "P3 %d %d 255 ", xSize, ySize);

	fwrite(header, sizeof(char), count, pFile);

	for (int i = 0; i < xSize * ySize; i++) {
		pixelBuffer[i].writePPM(pFile);
	}

	fclose(pFile);
}
