#pragma once
#include <vector>

#include "common.h"
#include "texture.h"
#include "parse_node.h"


const std::string MATERIAL_OBJECT = "material";

class Material;

extern std::map<std::string, Material*> glMaterialPool;

extern std::map<std::string, Texture*> glTexturePool;

class Material {
public:
	Material(ParseNode* loadNode) : texture(NULL) {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != MATERIAL_OBJECT) { throw LOAD_MATERIAL_DATA_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if (!SetMemberValue(it->GetType(), it->GetContext())) {
				throw MATERIAL_ATTRIBUTE_MISSING;
			}
		}
		glMaterialPool[name] = this;
	}
	~Material() {
		if (texture != NULL) {
			texture = NULL;
		}
	}
protected:
	bool SetMemberValue(std::string key, std::string value) {
		if ("name" == key) { name = value; }
		else if ("masking" == key) { masking = String2Bool(value); }
		else if ("alpha" == key) { alpha = String2Bool(value); }
		else if ("clamp" == key) { clamp = String2Bool(value); }
		else if ("envmap" == key) { envmap = String2Bool(value); }
		else if ("fogging" == key) { fogging = String2Bool(value); }
		else if ("culling" == key) { culling = String2Bool(value); }
		else if ("opacity" == key) { opacity = std::stof(value); }
		else if ("highlight" == key) { highlight = std::stof(value); }
		else if ("fps" == key) { fps = std::stof(value); }
		else if ("geometry" == key) { geometry = value; }
		else if ("texturing" == key) { texturing = value; }
		else if ("texturetwomode" == key) { texturetwomode = value; }
		else if ("shading" == key) { shading = value; }
		else if ("diffusecolour" == key) { diffusecolour = String2FloatVector(',', value); }
		else if ("ambientcolour" == key) { ambientcolour = String2FloatVector(',', value); }
		else if ("specularcolour" == key) { specularcolour = String2FloatVector(',', value); }
		else if ("selfillumination" == key) { selfillumination = String2FloatVector(',', value); }
		else if ("mask" == key) { mask = value; }
		else if ("texture" == key) {
			if (glTexturePool.find(value) == glTexturePool.end()) { return false; }
			texture = glTexturePool[value];
		}
		else {
			return false;
		}
		return true;
	}

	bool masking, alpha, clamp, envmap, fogging, culling;
	float opacity, highlight, fps;
	std::string name, geometry, texturing, texturetwomode, shading;
	Vector3 diffusecolour, ambientcolour, specularcolour, selfillumination, mask;
	Texture* texture;
};

