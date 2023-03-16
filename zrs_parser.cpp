#include "zrs_parser.h"

ZRSParser::ZRSParser(std::string str) : parseRoot(NULL), scene(NULL) {
	//check file type
	size_t pos = str.rfind('.');
	if (pos != std::string::npos) {
		std::string fileExt = str.substr(pos + 1);
		if (ZRS_FILE_EXT != fileExt) {
			throw FILE_EXTENSION_ERROR;
			return;
		}
	}
	std::string n = str.substr(0, str.find('.'));
	name = n;
}

ZRSParser::~ZRSParser() {
	auto delete_ptr = [](auto& ptr) {
		if (ptr != NULL) {
			delete ptr;
			ptr = NULL;
		}
	};

	delete_ptr(parseRoot);
	delete_ptr(scene);
	for (auto it : objects) { delete_ptr(it); }
	for (auto it : dummies) { delete_ptr(it); }
	for (auto it : spinners) { delete_ptr(it); }
}

void ZRSParser::ParserFile() {
	std::string fileName = DATA_PATH + name + "." + ZRS_FILE_EXT;
	// Open the file
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw FILE_OPEN_FLASE;
	}
	// Reading files into memory
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	std::stringstream contentBuff(content);
	//Parsing
	parseRoot = new ParseNode("root");
	parseRoot->Parse(contentBuff);
	//Load
	try {
		LoadFromParseNodes();
	}
	catch (int code) { throw code; }
}

void ZRSParser::LoadFromParseNodes() {
	if (NULL == parseRoot) { throw CODE_ERROR; }
	auto nodes = parseRoot->GetChildrens();
	try
	{
		for (auto it : nodes) {
			if (SCENE_OBJECT == it->GetType()) { scene = new Scene(it); }
			else if (OBJECT == it->GetType()) { objects.push_back(new Object(it)); }
			else if (SPINNER_OBJECT == it->GetType()) { spinners.push_back(new Spinner(it)); }
			else if (DUMMY_OBJECT == it->GetType()) { dummies.push_back(new Dummy(it)); }
			else {
				throw MEMBER_MISSING;
			}
		}
	}
	catch (ErrorCode code) { throw code; }
}

// Save mesh as OBJ file.
void ZRSParser::Write2OBJFormat() {
	if (NULL == scene) { throw CODE_ERROR; }
	std::string buffer = scene->ConvertMesh2ObjString();
	std::string fileName = OUT_PATH + name + "." + OBJ_FILE_EXT;
	try
	{
		WriteStringToFile(buffer, fileName);
	}
	catch (ErrorCode code)
	{
		throw code;
	}
	std::cout << "Write file: " << fileName << " success." << std::endl;
}