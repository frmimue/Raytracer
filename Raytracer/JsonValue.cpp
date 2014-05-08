#include "JsonValue.h"
#include "JsonArray.h"
#include "JsonGroup.h"

JsonValue::JsonValue(std::string value) : value(value){

}

JsonValue::~JsonValue(){

}

JsonArray JsonValue::Array(){
	return JsonArray(value);
}

JsonGroup JsonValue::Group(){
	return JsonGroup(value);
}

std::string JsonValue::String(){
	return value;
}

int JsonValue::Integer(){
	return std::stoi(value);
}

float JsonValue::Float(){
	return std::stof(value);
}