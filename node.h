#pragma once
#include "common.h"
#include "vector3.h"
#include "parse_node.h"

const std::string NODE_OBJECT = "node";

class Node;

static std::map<std::string, Node*> glNodePool;

class Node {
public:
	Node(ParseNode* loadNode){
		if (!loadNode) { throw CODE_ERROR; }

		auto attributes = loadNode->GetChildrens();
		for (auto it : attributes) {
			if (!SetMemberValue(it->GetName(), it->GetContext())) { throw NODE_ATTRIBUTE_MISSING; }
		}
		//Put into the node pool
		glNodePool[loadNode->GetName()] = this;
	}

	~Node() {

		for (auto it : children) {
			if (it != NULL) {
				delete it;
				it = NULL;
			}
		}
	}

	bool SetMemberValue(std::string key, std::string value) {
		if ("name" == key) { name = value; }
		else if ("parent" == key) {
			auto it = glNodePool.find(value);
			if (it == glNodePool.end()) { return false; }
			it->second->AddChildern(this);
		}
		else if ("translation" == key) { translation = value; }
		else if ("rotation" == key) { rotation = value; }
		else if ("scale" == key) { scale = value; }
		else if ("pivot" == key) { pivot = value; }
		else if ("altitude" == key) { altitude = std::stof(value); }
		else if ("collisionmasks" == key) { collisionmasks = String2FloatPair(',', value); }
		else if ("collisionmethod" == key) { collisionmethod = std::stoi(value); }
		else if ("option" == key) { options.push_back(value); }
		else if ("shadow" == key) { shadow = std::stoi(value); }
		else { return false; }
	}

	void AddChildern(Node* node) { 
		if (node) {
			children.push_back(node);
		}
	}

protected:
	int shadow, collisionmethod;
	float altitude;
	std::string name;
	Vector3 translation, rotation, scale, pivot;
	std::pair<float, float> collisionmasks;
	std::vector<std::string> options;
	std::vector<Node*> children;
};

