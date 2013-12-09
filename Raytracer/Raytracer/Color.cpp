#include "Color.h"


Color::Color() : red(0), green(0), blue(0)
{
}


Color::Color(const Color& rhs){
	red = rhs.red;
	green = rhs.green;
	blue = rhs.blue;
}


Color::Color(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}


Color::~Color()
{
}


Color Color::operator*(float const &f){
	return Color(red*f, green*f, blue*f);
}
