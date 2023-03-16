#pragma once
#include "common.h"

class ParseNode {
public:
	ParseNode(const std::string& n) : type(n) {}
	~ParseNode() {
		for (auto it : childrens) {
			if (NULL != it) {
				delete it;
				it = NULL;
			}
		}
	}

	std::string GetType() { return type; }
	std::string GetContext() { return context; }
	std::vector<ParseNode*> GetChildrens() { return childrens; }

	//Parsing nodes with recursion
	void Parse(std::stringstream& input);

	void PrintNode(int level);

	ParseNode* GetChildNode(const std::string& name) {
		for (auto it : childrens) {
			if (it->GetType() == name) {
				return it;
			}
		}
		return NULL;
	}
protected:
	std::string type, context;
	std::vector<ParseNode*> childrens;
};

