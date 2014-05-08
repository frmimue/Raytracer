#include "JsonArray.h"


JsonArray::JsonArray(std::string json){
	int eleStart, eleEnd, pos = 0;

	for (;; pos = eleEnd + 1){

		eleStart = json.find_first_of("-0123456789.\"{[", pos);

		if (eleStart == -1)
			break;

		if (json.at(eleStart) == '\"' || json.at(eleStart) == '{' || json.at(eleStart) == '['){
			eleStart++;
			eleEnd = JsonParser::findClosing(json, eleStart - 1) - 1;
		}
		else
			eleEnd = json.find_first_not_of("0123456789.", eleStart + 1) - 1;

		if (eleEnd == -2){
			array.push_back(json.substr(eleStart, json.size() -1));
			break;
		}

		array.push_back(json.substr(eleStart, eleEnd - eleStart + 1));
	}
}


JsonArray::~JsonArray()
{
}

JsonValue JsonArray::at(int index){
	return array.at(index);
}

int JsonArray::size(){
	return array.size();
}