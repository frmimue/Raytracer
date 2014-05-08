#pragma once

#include <string>

class JsonArray;
class JsonGroup;

class JsonValue
{
private:
	std::string value;
public:
	JsonValue(std::string value);
	~JsonValue();

	JsonArray   Array();
	JsonGroup	Group();

	std::string String();
	int			Integer();
	float		Float();
};

