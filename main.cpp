#include "zrs_parser.h"

extern::std::map<std::string, Material*> glMaterialPool;

void main() {
	try {
		ZRSParser* parser = new ZRSParser("new_church_a.zrs");
		parser->ParserFile();
		parser->Write2OBJFormat();
		delete parser;
	}
	catch (ErrorCode code) {
		switch (code) {
		case FILE_EXTENSION_ERROR:
		{
			std::cout << "File type error." << std::endl;
			break;
		}
		case FILE_OPEN_FLASE:
		{
			std::cout << "Open file false." << std::endl;
			break;
		}
		case CODE_ERROR:
		{
			std::cout << "Parsering false, data: ";
			break;
		}
		case LOAD_SCENE_DATA_ERROR:
		{
			std::cout << "Load scene data error: ";
			break;
		}
		case LOAD_NODE_DATA_ERROR:
		{
			std::cout << "Load node data error: ";
			break;
		}
		default:
			std::cout << "Code error." << std::endl;
		}
	}
	std::cin.get();
}