#pragma once
#include "common.h"

class Vector3 {
public:
	float x, y, z;

	Vector3(){}
	Vector3(const std::vector<float> &arr) {
		if (arr.size() < 3) { return; }
		x = arr[0];
		y = arr[1];
		z = arr[2];
	}
	~Vector3(){}

	std::string Convert2ObjectFormat(const float &index) {
		std::ostringstream objStream;
		objStream << " " << x + index << " " << y + index << " " << z + index << std::endl;
		return objStream.str();
	}

	float GetMaxMember() {
		float ret = x;
		if (y > ret) { ret = y; }
		if (z > ret) { ret = z; }
		return ret;
	}

	inline void operator =(const std::string &str) {
		auto arr = String2FloatVector(',', str);
		if (arr.size() < 3) { return; }
		x = arr[0];
		y = arr[1];
		z = arr[2];
	}

};