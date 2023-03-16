#pragma once
#include <string>

#include "vector3.h"
#include "parse_node.h"

const std::string TEXTURE_OBJECT = "texture";

class Texture {
public:
	Texture(ParseNode* loadNode) {
		if (loadNode->GetName() != TEXTURE_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if ("name" == it->GetName()) { 
				name = it->GetContext();
			}
			else if ("file") {
				file = it->GetContext();
			}
			else {
				throw TEXTRUE_ATTRIBUTE_MISSING;
			}
		}
	}
	~Texture() {}

	bool LoadTexture(); //todo
protected:
	std::string name, file;
};

