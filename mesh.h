#pragma once

#include "common.h"
#include "vector3.h"
#include "vertex.h"
#include "node.h"
#include "parse_node.h"

const std::string MESH_OBJECT = "mesh";

class Mesh;

extern std::map<std::string, Mesh*> glMeshPool;
extern std::map<std::string, Node*> glNodePool;

class Mesh : public Node {
public:
	Mesh() : Node() {}
	Mesh(ParseNode* loadNode) : Node() {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != MESH_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if (!SetMemberValue(it->GetType(), it->GetContext())) {
				throw MESH_ATTRIBUTE_MISSING;
			}
		}
		glMeshPool[name] = this;
		glNodePool[name] = this;
	}
	~Mesh() {}


	std::string Convert2ObjString(float &index) {
		//The vertex index of obj starts at 1
		index++;
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
		float maxIndex = 0;
		for (auto it : triangles) {
			objStream << "f";
			objStream << it.Convert2ObjectFormat(index);
			float mi = it.GetMaxMember();
			if (mi > maxIndex) {
				maxIndex = mi;
			}
		}
		//Index postponement
		index += maxIndex;
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



