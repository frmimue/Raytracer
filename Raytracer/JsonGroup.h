#pragma once

#include <string>
#include <map>

#include "JsonParser.h"
#include "JsonValue.h"

class JsonGroup
{
private:
	std::map<std::string, JsonValue> group;
public:
	JsonGroup(std::string);
	~JsonGroup();
	JsonValue at(std::string);
};

