#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

#include "error_code.h"

#define DATA_PATH "./Data/"
#define OUT_PATH "./Out/"
#define DECIMAL_POINT_LIMIT 10

//Strings are converted to int arrays based on sign separation
extern std::vector<float> String2FloatVector(const char divide, const std::string str);

extern std::pair<float, float> String2FloatPair(const char divide, const std::string str);

extern bool String2Bool(const std::string& str);

extern std::string Float2String(const float &value);

extern std::string RemoveChar(char divide, std::string& str);

extern void WriteStringToFile(const std::string& content, const std::string& filename);