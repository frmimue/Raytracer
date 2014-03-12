#include "JsonGroup.h"


JsonGroup::JsonGroup(std::string json){
	int keyStart, keyEnd, valueStart, valueEnd, tmp, pos = 0;

	for (;; pos = valueEnd + 2){

		keyStart = json.find_first_of('"', pos) + 1;
		keyEnd = json.find_first_of('"', keyStart) - 1;

		tmp = json.find_first_of(':', keyEnd + 2);

		valueStart = json.find_first_of("0123456789\"{[", tmp + 1);
		if (json.at(valueStart) == '\"' || json.at(valueStart) == '{' || json.at(valueStart) == '['){
			valueStart++;
			valueEnd = JsonParser::findClosing(json, valueStart - 1) - 1;
		}
		else
			valueEnd = json.find_first_not_of("0123456789", tmp + 1) - 1;

		if (keyStart == 0 || keyEnd == 0 || valueEnd == -2)
			break;

		group.insert(std::pair<std::string, std::string>(json.substr(keyStart, keyEnd - keyStart + 1), json.substr(valueStart, valueEnd - valueStart + 1)));
	}
}


JsonGroup::~JsonGroup(){
}

JsonValue JsonGroup::at(std::string key){
	return group.at(key);
}
