#include "Color.h"


Color::Color() : red(0), green(0), blue(0) {
}


Color::Color(const Color &rhs) {
    red = rhs.red;
    green = rhs.green;
    blue = rhs.blue;
}


Color::Color(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}


Color::~Color() {
}


Color Color::operator*(float const &f) {
    if(f > 1.0f)
        return Color(red, green, blue);
	if (f < 0.0f)
		return Color(0, 0, 0);

    return Color(red * f, green * f, blue * f);
}


Color Color::operator+(Color const &c) {
    Color color = Color(this->red + c.red, this->green + c.green, this->blue + c.blue);
    color.validate();
    return color;
}

void Color::validate() {
    if(red > 255)
        red = 255;

    if(green > 255)
        green = 255;

    if(blue > 255)
        blue = 255;
}


void Color::writePPM(FILE *pFile) {
	char buffer[16];
	int count = sprintf(buffer, "%d %d %d ", red, green, blue);
	fwrite(buffer, sizeof(char), count, pFile);
}

void Color::writeBMP(FILE *pFile) {
	char buffer[3] = { 0 };

	buffer[0] = blue;
	buffer[1] = green;
	buffer[2] = red;

	fwrite(buffer, sizeof(char), 3, pFile);
}

bool Color::isNull() {
    if(red < 5 && green < 5 && blue < 5)
        return true;

    return false;
}
