#pragma once
#include "node.h"
#include "animator.h"
#include "node.h"

const std::string SPINNER_OBJECT = "spinner";


class Spinner : public Node {
public:
	Spinner(ParseNode* loadNode) : Node(loadNode->GetChildNode(NODE_OBJECT)) {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != SPINNER_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		try {
			for (auto it : attrs) {
				if (ANIMATOR_OBJECT == it->GetType()) {
					animator = new Animator(it);
				}
				else if ("parent" == it->GetType()) {
					auto pIt = glNodePool.find(it->GetContext());
					pIt->second->AddChildern(this);
				}
				else if (NODE_OBJECT == it->GetType()) { continue; }
				else if (!SetMemberValue(it->GetType(), it->GetContext())) {
					throw SPINNER_ATTRIBUTE_MISSING;
				}
			}
		}
		catch (ErrorCode code) { throw code; }
	}
	~Spinner() {
		auto delete_ptr = [](auto& ptr) {
			if (ptr != NULL) {
				delete ptr;
				ptr = NULL;
			}
		};

		delete_ptr(animator);
	}
protected:
	bool SetMemberValue(std::string key, std::string value) override {
		if ("name" == key) { name = value; }
		else if ("axis" == key) { axis = value; }
		else if ("min" == key) { min = std::stof(value); }
		else if ("max" == key) { max = std::stof(value); }
		else {
			return false;
		}
		return true;
	}

	float min, max;
	std::string axis;
	Animator* animator;
};