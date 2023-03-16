#pragma once
#include <string>
#include "parse_node.h"

const std::string ANIMATOR_OBJECT = "animator";

class Animator{
public:
	Animator(ParseNode* loadNode) {
		if (!loadNode) { throw CODE_ERROR; }
		if (loadNode->GetType() != ANIMATOR_OBJECT) { throw CODE_ERROR; }
		auto attrs = loadNode->GetChildrens();
		for (auto it : attrs) {
			if (!SetMemberValue(it->GetType(), it->GetContext())) {
				throw ANIMATOR_ATTRIBUTE_MISSING;
			}
		}
		std::cout << std::endl;
	}
	~Animator(){}
protected:
	bool SetMemberValue(std::string key, std::string value) {
		if ("framestep" == key) { framestep = std::stoi(value); }
		else if ("framerate" == key) { framerate = std::stof(value); }
		else if ("duration" == key) { duration = std::stof(value); }
		else if ("phase" == key) { phase = std::stof(value); }
		else if ("delay" == key) { delay = std::stof(value); }
		else if ("mode" == key) { mode = value; }
		else if ("updatemode" == key) { updatemode = value; }
		else {
			return false;
		}
		return true;
	}

	int framestep;
	float framerate, duration, phase, delay;
	std::string mode, updatemode;
};