#pragma once
#include "node.h"

class Dummy {
public:
	Dummy() {}
	~Dummy() {
		if (node != NULL) {
			delete node;
			node = NULL;
		}
	}
protected:
	bool flag;
	Node* node;
};