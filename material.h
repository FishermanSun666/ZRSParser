#pragma once
#include <vector>

#include "common.h"
#include "texture.h"

class Material;

extern std::map<std::string, Material*> glMaterialPool;

class Material {
public:
	Material() {}
	~Material() {
		if (texture != NULL) {
			delete texture;
			texture = NULL;
		}
	}
protected:
	bool masking, alpha, clamp, envmap, fogging, culling;
	float opacity, highlight, fps;
	std::string name, geometry, texturing, texturetwomode, shading;
	Vector3 diffusecolour, ambientcolour, specularcolour, selfillumination;
	Texture* texture;
	std::vector<int> mask;
};

