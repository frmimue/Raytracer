#include "JsonParser.h"

#include <map>

static const std::map<char, char> charMap = { { '{', '}' }, { '[', ']' }, { '"', '"' } };

JsonParser::JsonParser(){
}


JsonParser::~JsonParser(){
}

int JsonParser::findClosing(std::string str, int pos){

	char open	= str.at(pos);
	char close	= charMap.at(open);

	pos++;

	for (; pos < str.size(); pos++){
		if (str.at(pos) == close)
			return pos;
		if (str.at(pos) == open)
			pos = findClosing(str, pos);
	}

	return -1;
}