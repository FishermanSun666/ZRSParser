#pragma once
#include "node.h"
#include "texture.h"
#include "material.h"
#include "mesh.h"
#include "object.h"
#include "dummy.h"
#include "spinner.h"
#include "parse_node.h"

const std::string SCENE_OBJECT = "scene";

extern std::map<std::string, Material*> glMaterialPool;
extern std::map<std::string, Mesh*> glMeshPool;

class Scene : public Node {
public:
	Scene(ParseNode* loadNode) : Node(loadNode->GetChildNode(NODE_OBJECT)), textures(), materials(), meshes() {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != SCENE_OBJECT) { throw CODE_ERROR; }
		auto members = loadNode->GetChildrens();
		//Load all member
		try {
			for (auto it : members) {
				if (TEXTURE_OBJECT == it->GetType()) {
					Texture* tex = new Texture(it);
					textures.push_back(tex);
				}
				else if (MATERIAL_OBJECT == it->GetType()) {
					Material* mat = new Material(it);
					materials.push_back(mat);
				}
				else if (MESH_OBJECT == it->GetType()) {
					Mesh* mesh = new Mesh(it);
					meshes.push_back(mesh);
				}
				else if (NODE_OBJECT == it->GetType()) {
					continue;
				}
				else {
					throw SCENE_ATTRIBUTE_MISSING;
				}
			}
		}
		catch (int code) { throw code; }
		glNodePool[name] = this;
	}
	~Scene(){
		auto delete_ptr = [](auto& ptr) {
			if (ptr != NULL) {
				delete ptr;
				ptr = NULL;
			}
		};

		for (auto it : textures) { delete_ptr(it); }
		for (auto it : materials) { delete_ptr(it); }
		for (auto it : meshes) { delete_ptr(it); }
	}

	std::string ConvertMesh2ObjString() {
		if (0 == meshes.size()) { return ""; }
		std::ostringstream objStream;
		float index = 0.0f;
		for (auto it : meshes) {
			objStream << it->Convert2ObjString(index);
		}
		return objStream.str();
	}

protected:
	std::vector<Texture*> textures;
	std::vector<Material*> materials;
	std::vector<Mesh*> meshes;
};