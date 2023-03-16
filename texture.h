#pragma once
#include <string>

#include "vector3.h"
#include "parse_node.h"

const std::string TEXTURE_OBJECT = "texture";

class Texture;

extern std::map<std::string, Texture*> glTexturePool;

class Texture {
public:
	Texture(ParseNode* loadNode) {
		if (loadNode->GetType() != TEXTURE_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if ("name" == it->GetType()) { 
				name = it->GetContext();
			}
			else if ("file") {
				file = it->GetContext();
			}
			else {
				throw TEXTRUE_ATTRIBUTE_MISSING;
			}
		}
		glTexturePool[name] = this;
	}
	~Texture() {}

	bool LoadTexture() {} //todo
protected:
	std::string name, file;
};

