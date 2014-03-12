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


void Color::writePPM(std::ofstream *stream) {
    *stream << red << " " << green << " " << blue << " ";
}

bool Color::isNull() {
    if(red < 5 && green < 5 && blue < 5)
        return true;

    return false;
}
