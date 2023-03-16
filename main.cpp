#include "zrs_parser.h"

std::map<std::string, Node*> glNodePool;
std::map<std::string, Texture*> glTexturePool;
std::map<std::string, Material*> glMaterialPool;
std::map<std::string, Mesh*> glMeshPool;

void main() {
	try {
		ZRSParser* parser = new ZRSParser("new_church_a.zrs");
		parser->ParserFile();
		parser->Write2OBJFormat();
		delete parser;
	}
	catch (ErrorCode code) {
		ExceptionHandling(code);
	}
	std::cin.get();
}