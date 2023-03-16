#pragma once

#include "common.h"
#include "vector3.h"
#include "vertex.h"
#include "parse_node.h"

const std::string MESH_OBJECT = "mesh";

class Mesh;

static std::map<std::string, Mesh*> glMeshPool;

class Mesh {
public:
	Mesh(ParseNode* loadNode) {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetName() != MESH_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if (!SetMemberValue(it->GetName(), it->GetContext())) {
				throw MESH_ATTRIBUTE_MISSING;
			}
		}
		glMeshPool[loadNode->GetName()] = this;
	}
	~Mesh() {}

	std::string Convert2ObjString() {
		std::ostringstream objStream;
		objStream << "o " << name << std::endl;
		//position, texture, normal
		for (auto it : vertices) {
			objStream << it.ConvertPosition2ObjFormat();
		}
		for (auto it : vertices) {
			objStream << it.ConvertTexCoord2ObjFormat();
		}
		for (auto it : vertices) {
			objStream << it.ConvertNormal2ObjFormate();
		}
		//face
		int index = 0;
		for (auto it : triangles) {
			if (0 == index) {
				objStream << "f";
			}
			objStream << it.Convert2ObjectFormat();
			if (index >= 2) {
				objStream << std::endl;
				index = 0;
				continue;
			}
			index++;
		}
		objStream << std::endl;
		return objStream.str();
	}

protected:
	bool SetMemberValue(std::string key, std::string value) {
		if ("name" == key) { name = value; }
		else if ("flag" == key) { flag = value; }
		else if ("size" == key) { size = String2FloatPair(',', value); }
		else if ("vertex" == key) { vertices.push_back(Vertex(String2FloatVector(',', value))); }
		else if ("tri" == key) { triangles.push_back(Vector3(String2FloatVector(',', value))); }
		else if ("kflcount" == key) { kflcount = std::stoi(value); }
		else if ("kfltrans" == key) { kfltrans.push_back(String2FloatVector(',',value)); }
		else {
			return false;
		}
		return true;
	}

	int kflcount;
	std::string name, flag;
	std::pair<float, float> size;
	std::vector<Vertex> vertices;
	std::vector<Vector3> triangles;
	std::vector<std::vector<float>> kfltrans;
};



