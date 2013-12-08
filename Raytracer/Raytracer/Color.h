#pragma once
class Color
{
public:
	int red;
	int green;
	int blue;

	Color();
	Color(const Color&);
	Color(int, int, int);
	~Color();
};

