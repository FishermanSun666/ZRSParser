#pragma once
#include "common.h"

class ParseNode {
public:
	ParseNode(const std::string& n) : name(n) {}
	~ParseNode() {
		for (auto it : childrens) {
			if (NULL != it) {
				delete it;
				it = NULL;
			}
		}
	}

	std::string GetName() { return name; }
	std::string GetContext() { return context; }
	std::vector<ParseNode*> GetChildrens() { return childrens; }

	//Parsing nodes with recursion
	void Parse(std::stringstream& input);

	void PrintNode(int level);
protected:
	std::string name, context;
	std::vector<ParseNode*> childrens;
};

