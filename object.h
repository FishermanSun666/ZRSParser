#pragma once
#include "node.h"
#include "mesh.h"
#include "material.h"

class Object {
public:
	Object() {}
	~Object() {
		auto delete_ptr = [](auto& ptr) {
			if (ptr != NULL) {
				delete ptr;
				ptr = NULL;
			}
		};

		delete_ptr(node);
		delete_ptr(mesh);
		delete_ptr(material);
	}
protected:
	std::string name, parent;
	Node* node;
	Mesh* mesh;
	Material* material;
};
