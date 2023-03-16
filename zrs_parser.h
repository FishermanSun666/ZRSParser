#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include "error_code.h"
#include "scene.h"
#include "parse_node.h"
#include "common.h"

const std::string ZRS_FILE_EXT = "zrs";
const std::string OBJ_FILE_EXT = "obj";

class ZRSParser
{
public:
	ZRSParser(std::string str);
	~ZRSParser();
	void ParserFile();
	void LoadFromParseNodes();
	void Write2OBJFormat();
protected:
	std::string name;
	ParseNode* parseRoot;

	Scene* scene;
	std::vector<Object*> objects;
	std::vector<Dummy*> dummies;
	std::vector<Spinner*> spinners;
};

