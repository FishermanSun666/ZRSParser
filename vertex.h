#pragma once
#include <vector>
#include <sstream>

#include "vector3.h"

class Vertex {
public:
	Vertex(const std::vector<float> &params) : position(), normal(){
		if (params.size() != 8) { return; }
		int index = 0;
		for (auto it : params) {
			if (0 == index) { position.x = it; }
			if (1 == index) { position.y = it; }
			if (2 == index) { position.z = it; }
			if (3 == index) { texCoord.first = it; }
			if (4 == index) { texCoord.second = it; }
			if (5 == index) { normal.x = it;}
			if (6 == index) { normal.y = it; }
			if (7 == index) { normal.z = it; }
			index++;
		}
	}
	~Vertex() {}

	Vector3 GetPosition() { return position; }

	std::string ConvertPosition2ObjFormat() {
		std::ostringstream objStream;

		objStream << "v " << Float2String(position.x) << " " << Float2String(position.y) << " " << Float2String(position.z) << std::endl;

		return objStream.str();
	}

	std::string ConvertTexCoord2ObjFormat() {
		std::ostringstream objStream;

		objStream << "vt " << Float2String(texCoord.first) << " " << Float2String(texCoord.second) << std::endl;

		return objStream.str();

	}

	std::string ConvertNormal2ObjFormate() {
		std::ostringstream objStream;

		objStream << "vn " << Float2String(normal.x) << " " << Float2String(normal.y) << " " << Float2String(normal.z) << std::endl;

		return objStream.str();
	}
protected: 
	Vector3 position;
	std::pair<float, float> texCoord;
	Vector3 normal;
};