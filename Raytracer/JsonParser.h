#pragma once

#include <string>

class JsonParser
{
public:
	JsonParser();
	~JsonParser();
	static int findClosing(std::string, int);
};

