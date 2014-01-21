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
    std::ofstream data;
    data.open(file);
    data << "P3" << " " << xSize << " " << ySize << " " << "255" << " ";

    for(int i = 0; i < xSize * ySize; i++) {
        pixelBuffer[i].writePPM(&data);
    }

    data.close();
}
