#pragma once
#include "node.h"
#include "mesh.h"
#include "material.h"

class Object;

const std::string OBJECT = "object";

extern std::map<std::string, Material*> glMaterialPool;
extern std::map<std::string, Mesh*> glMeshPool;

class Object : public Node {
public:
	Object(ParseNode* loadNode) : Node(loadNode->GetChildNode(NODE_OBJECT)), parent(NULL), mesh(NULL), material(NULL) {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != OBJECT) { throw CODE_ERROR; }
		auto members = loadNode->GetChildrens();
		try {
			for (auto it : members) {
				if ("name" == it->GetType()) { 
					name = it->GetContext(); 
				}
				else if ("parent" == it->GetType()) {
					if (glNodePool.find(it->GetContext()) == glNodePool.end()) { throw DATA_ERROR; }
					parent = glNodePool[it->GetContext()];
				}
				else if (NODE_OBJECT == it->GetType()) {
					continue;
				}
				else if ("part" == it->GetType()) {
					LoadPartData(it);
				}
				else {
					throw OBJECT_ATTRIBUTE_MISSING;
				}
			}
		}
		catch (ErrorCode code) { throw code; }
	}
	~Object() {
		auto delete_ptr = [](auto& ptr) {
			if (ptr != NULL) {
				ptr = NULL;
			}
		};

		delete_ptr(parent);
		delete_ptr(mesh);
		delete_ptr(material);
	}
protected:
	void LoadPartData(ParseNode* loadNode) {
		if (!loadNode) { throw CODE_ERROR; }
		if ("part" != loadNode->GetType()) { throw CODE_ERROR; }
		auto members = loadNode->GetChildrens();
		for (auto it : members) {
			if (MESH_OBJECT == it->GetType()) {
				if (glMeshPool.find(it->GetContext()) == glMeshPool.end()) { throw DATA_ERROR; }
				mesh = glMeshPool[it->GetContext()];
			}
			else if (MATERIAL_OBJECT == it->GetType()) { 
				if (glMaterialPool.find(it->GetContext()) == glMaterialPool.end()) { throw DATA_ERROR; }
				material = glMaterialPool[it->GetContext()];
			}
			else {
				throw OBJECT_ATTRIBUTE_MISSING;
			}
		}
	}

	std::string name;
	Node* parent;
	Mesh* mesh;
	Material* material;
};
