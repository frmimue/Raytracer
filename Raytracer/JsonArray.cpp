#include "JsonArray.h"


JsonArray::JsonArray(std::string json){
	int eleStart, eleEnd, pos = 0;

	for (;; pos = eleEnd + 2){

		eleStart = json.find_first_of("0123456789\"{[", pos);

		if (eleStart == -1)
			break;

		if (json.at(eleStart) == '\"' || json.at(eleStart) == '{' || json.at(eleStart) == '['){
			eleStart++;
			eleEnd = JsonParser::findClosing(json, eleStart - 1) - 1;
		}
		else
			eleEnd = json.find_first_not_of("0123456789", eleStart + 1) - 1;

		if (eleEnd == -2)
			break;

		array.push_back(json.substr(eleStart, eleEnd - eleStart + 1));
	}
}


JsonArray::~JsonArray()
{
}

JsonValue JsonArray::at(int index){
	return array.at(index);
}