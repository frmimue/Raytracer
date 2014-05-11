#pragma once

#include <fstream>

class Color {
private:
    int red;
    int green;
    int blue;
public:
    Color();
    Color(const Color &);
    Color(int, int, int);
    ~Color();
    Color operator*(float const &);
    Color operator+(Color const &);
    void validate();
	void writePPM(FILE *);
	void writeBMP(FILE *);
    bool isNull();
};
