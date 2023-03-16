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

class Scene {
public:
	Scene(ParseNode* loadNode) {
		if (!loadNode) { throw CODE_ERROR; }
		// Iterate over all child nodes
		if (loadNode->GetName() != SCENE_OBJECT) { throw CODE_ERROR; }
		auto members = loadNode->GetChildrens();
		try {
			for (auto it : members) {
				if (NODE_OBJECT == it->GetName()) {
					Node* node = new Node(it);
					nodes.push_back(node);
				}
				if (TEXTURE_OBJECT == it->GetName()) {
					Texture* tex = new Texture(it);
					textures.push_back(tex);
				}
				else if (MESH_OBJECT == it->GetName()) {
					Mesh* mesh = new Mesh(it);
					meshes.push_back(mesh);
					mesh->Convert2ObjString();
				}
			}
		}
		catch (int code) { throw code; }
	}
	~Scene(){
		auto delete_ptr = [](auto& ptr) {
			if (ptr != NULL) {
				delete ptr;
				ptr = NULL;
			}
		};
		for (auto it : nodes) { delete_ptr(it); }
		for (auto it : textures) { delete_ptr(it); }
		for (auto it : materials) { delete_ptr(it); }
		for (auto it : meshes) { delete_ptr(it); }
		for (auto it : objects) { delete_ptr(it); }
		for (auto it : dummies) { delete_ptr(it); }
		for (auto it : spinners) { delete_ptr(it); }
	}

	std::string ConvertMesh2ObjString() {
		if (0 == meshes.size()) { return ""; }
		std::ostringstream objStream;
		for (auto it : meshes) {
			objStream << it->Convert2ObjString();
		}
		return objStream.str();
	}

protected:
	std::vector<Node*> nodes;
	std::vector<Texture*> textures;
	std::vector<Material*> materials;
	std::vector<Mesh*> meshes;
	std::vector<Object*> objects;
	std::vector<Dummy*> dummies;
	std::vector<Spinner*> spinners;
};