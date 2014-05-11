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

void PixelBuffer::saveBMP(std::string file) {
	FILE *pFile = fopen(file.c_str(), "wb");

	char header[54] = { 0 };

	header[0] = 0x42;
	header[1] = 0x4d;
	header[10] = 54;
	header[14] = 40;
	//header[18] = 0xFF;
	//header[19] = 0x04;
	//header[22] = 0xFF;
	//header[23] = 0x04;
	header[18] = 0xFF & (xSize >> 0);
	header[19] = 0xFF & (xSize >> 8);
	header[20] = 0xFF & (xSize >> 16);
	header[21] = 0xFF & (xSize >> 24);
	header[22] = 0xFF & (ySize >> 0);
	header[23] = 0xFF & (ySize >> 8);
	header[24] = 0xFF & (ySize >> 16);
	header[25] = 0xFF & (ySize >> 24);
	header[26] = 1;
	header[28] = 24;

	fwrite(header, sizeof(char), 54, pFile);

	char filler[3] = { 0 };

	for (int i = ySize-1; i >= 0; i--){
		for (int j = 0; j < xSize; j++){
			pixelBuffer[i*xSize + j].writeBMP(pFile);
		}
		if (xSize%4 != 0)
			fwrite(filler, sizeof(char), 4-xSize%4, pFile);
	}

	//for (int i = 0; i < xSize * ySize; i++) {
	//	pixelBuffer[i].writeBMP(pFile);
	//}

	fclose(pFile);
}
