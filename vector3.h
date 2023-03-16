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

	std::string Convert2ObjectFormat() {
		std::ostringstream objStream;
		objStream << " " << x << "/" << y << "/" << z;
		return objStream.str();
	}

	inline void operator =(const std::string str) {
		auto arr = String2FloatVector(',', str);
		if (arr.size() < 3) { return; }
		x = arr[0];
		y = arr[1];
		z = arr[2];
	}

};