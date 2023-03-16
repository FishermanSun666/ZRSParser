#pragma once
#include "node.h"

const std::string DUMMY_OBJECT = "dummy";

class Dummy : public Node {
public:
	Dummy(ParseNode* loadNode) : Node(loadNode->GetChildNode(NODE_OBJECT)) {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != DUMMY_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if ("flag" == it->GetType()) { flag = String2Bool(
				it->GetContext()); 
			}
			else if (NODE_OBJECT == it->GetType()) {
				continue;
			}
			else {
				throw DUMMY_ATTRIBUTE_MISSING;
			}
		}
	}
	~Dummy() {}
protected:
	bool flag;
	Node* node;
};