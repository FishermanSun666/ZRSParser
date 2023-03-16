#include "zrs_parser.h"
#include "error_code.h"

std::map<std::string, Node*> glNodePool;
std::map<std::string, Texture*> glTexturePool;
std::map<std::string, Material*> glMaterialPool;
std::map<std::string, Mesh*> glMeshPool;

void ErrorProcessing(ErrorCode code) {
	switch (code) {
	case FILE_EXTENSION_ERROR:
		std::cout << "File type error." << std::endl;
		break;
	case FILE_OPEN_FLASE:
		std::cout << "Open file false." << std::endl;
		break;
	case CODE_ERROR:
		std::cout << "Parsing false, data error." << std::endl;
		break;
	case DATA_ERROR:
		std::cout << "Data error." << std::endl;
		break;
	case MEMBER_MISSING:
		std::cout << "Member missing." << std::endl;
		break;
	case LOAD_SCENE_DATA_ERROR:
		std::cout << "Load scene data error." << std::endl;
		break;
	case SCENE_ATTRIBUTE_MISSING:
		std::cout << "Scene attribute missing." << std::endl;
		break;
	case LOAD_NODE_DATA_ERROR:
		std::cout << "Load node data error." << std::endl;
		break;
	case NODE_ATTRIBUTE_MISSING:
		std::cout << "Node attribute missing." << std::endl;
		break;
	case LOAD_TEXTURE_DATA_ERROR:
		std::cout << "Load texture data error." << std::endl;
		break;
	case TEXTRUE_ATTRIBUTE_MISSING:
		std::cout << "Texture attribute missing." << std::endl;
		break;
	case LOAD_MATERIAL_DATA_ERROR:
		std::cout << "Load material data error." << std::endl;
		break;
	case MATERIAL_ATTRIBUTE_MISSING:
		std::cout << "Material attribute missing." << std::endl;
		break;
	case LOAD_MESH_DATA_ERROR:
		std::cout << "Load mesh data error." << std::endl;
		break;
	case MESH_ATTRIBUTE_MISSING:
		std::cout << "Mesh attribute missing." << std::endl;
		break;
	case OBJECT_ATTRIBUTE_MISSING:
		std::cout << "Object attribute missing." << std::endl;
		break;
	case OBJECT_PART_ATTRIBUTE_MISSING:
		std::cout << "Object part attribute missing." << std::endl;
		break;
	case SPINNER_ATTRIBUTE_MISSING:
		std::cout << "Spinner attribute missing." << std::endl;
		break;
	case ANIMATOR_ATTRIBUTE_MISSING:
		std::cout << "Animator attribute missing." << std::endl;
		break;
	case DUMMY_ATTRIBUTE_MISSING:
		std::cout << "Dummy attribute missing." << std::endl;
		break;
	case OPEN_FILE_FASLE:
		std::cout << "Open file false." << std::endl;
		break;
	case WRITE_FILE_ERROR:
		std::cout << "Write file error." << std::endl;
		break;
	default:
		std::cout << "Unknown error." << std::endl;
	}
}

void main() {
	try {
		ZRSParser* parser = new ZRSParser("new_church_a.zrs");
		parser->ParserFile();
		parser->Write2OBJFormat();
		delete parser;
	}
	catch (ErrorCode code) {
		ErrorProcessing(code);
	}
	std::cin.get();
}