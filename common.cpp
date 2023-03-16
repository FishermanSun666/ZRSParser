#include "common.h"
#include <charconv>

extern std::vector<float> String2FloatVector(const char divide, const std::string str) {
	std::stringstream ss(str);
	std::string item;
	std::vector<float> floatVec;

	while (std::getline(ss, item, divide)) {
		float tmp = std::stof(item);
		floatVec.push_back(tmp);
	}

	return floatVec;
}

extern std::pair<float, float> String2FloatPair(const char divide, const std::string str) {
	std::stringstream ss(str);
	std::string item;
	std::pair<float, float> intPair;
	int index = 0;
	while (std::getline(ss, item, divide)) {
		if (0 == index) {
			intPair.first = std::stof(item);
			index++;
		}
		else if (1 == index) {
			intPair.second = std::stof(item);
			return intPair;
		}
		else {
			return intPair;
		}
	}
}

extern bool String2Bool(const std::string& str) {
	if (str == "on") {
		return true;
	}
	else {
		return false;
	}
}

extern std::string Float2String(const float &value) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(DECIMAL_POINT_LIMIT) << value;
	return oss.str();// CutTrimDecimalPlaces(oss.str(), DECIMAL_POINT_LIMIT);
}

extern std::string RemoveChar(const char divide, std::string& str) {
	int n = str.length();
	int i = 0, j = 0;
	while (i < n) {
		if (str[i] != divide) {
			str[j++] = str[i];
		}
		i++;
	}
	str.resize(j);
	return str;
}

extern void WriteStringToFile(const std::string& content, const std::string& filename) {
	std::ofstream outFile(filename, std::ios::out | std::ios::binary);

	if (!outFile.is_open()) {
		throw OPEN_FILE_FASLE;
	}

	outFile.write(content.c_str(), content.size());

	if (!outFile) {
		outFile.close();
		throw WRITE_FILE_ERROR;
	}

	outFile.close();
}