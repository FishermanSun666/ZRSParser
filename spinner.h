#pragma once
#include "node.h"
#include "animator.h"

class Spinner {
public:
	Spinner() {}
	~Spinner() {
		auto delete_ptr = [](auto& ptr) {
			if (ptr != NULL) {
				delete ptr;
				ptr = NULL;
			}
		};

		delete_ptr(node);
		delete_ptr(animator);
	}
protected:
	float min, max;
	std::string name, parent;
	std::string axis;
	Node* node;
	Animator* animator;
};