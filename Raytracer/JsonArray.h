#pragma once

#include <string>
#include <vector>

#include "JsonParser.h"
#include "JsonValue.h"

class JsonArray
{
private:
	std::vector<JsonValue> array;
public:
	JsonArray(std::string);
	~JsonArray();
	JsonValue at(int);
};

