#pragma once

const enum ErrorCode {
	FILE_EXTENSION_ERROR,
	FILE_OPEN_FLASE,
	CODE_ERROR,
	DATA_ERROR,
	MEMBER_MISSING,
	LOAD_SCENE_DATA_ERROR,
	SCENE_ATTRIBUTE_MISSING,
	LOAD_NODE_DATA_ERROR,
	NODE_ATTRIBUTE_MISSING,
	LOAD_TEXTURE_DATA_ERROR,
	TEXTRUE_ATTRIBUTE_MISSING,
	LOAD_MATERIAL_DATA_ERROR,
	MATERIAL_ATTRIBUTE_MISSING,
	LOAD_MESH_DATA_ERROR,
	MESH_ATTRIBUTE_MISSING,
	OBJECT_ATTRIBUTE_MISSING,
	OBJECT_PART_ATTRIBUTE_MISSING,
	SPINNER_ATTRIBUTE_MISSING,
	ANIMATOR_ATTRIBUTE_MISSING,
	DUMMY_ATTRIBUTE_MISSING,
	OPEN_FILE_FASLE,
	WRITE_FILE_ERROR,
};

void ExceptionHandling(ErrorCode code) {
	switch (code) {
	case FILE_EXTENSION_ERROR:
		std::cout << "File type error." << std::endl;
		break;
	case FILE_OPEN_FLASE:
		std::cout << "Open file false." << std::endl;
		break;
	case CODE_ERROR:
		std::cout << "Parsing false, data: " << std::endl;
		break;
	case DATA_ERROR:
		std::cout << "Data error." << std::endl;
		break;
	case MEMBER_MISSING:
		std::cout << "Member missing." << std::endl;
		break;
	case LOAD_SCENE_DATA_ERROR:
		std::cout << "Load scene data error: " << std::endl;
		break;
	case SCENE_ATTRIBUTE_MISSING:
		std::cout << "Scene attribute missing." << std::endl;
		break;
	case LOAD_NODE_DATA_ERROR:
		std::cout << "Load node data error: " << std::endl;
		break;
	case NODE_ATTRIBUTE_MISSING:
		std::cout << "Node attribute missing." << std::endl;
		break;
	case LOAD_TEXTURE_DATA_ERROR:
		std::cout << "Load texture data error: " << std::endl;
		break;
	case TEXTRUE_ATTRIBUTE_MISSING:
		std::cout << "Texture attribute missing." << std::endl;
		break;
	case LOAD_MATERIAL_DATA_ERROR:
		std::cout << "Load material data error: " << std::endl;
		break;
	case MATERIAL_ATTRIBUTE_MISSING:
		std::cout << "Material attribute missing." << std::endl;
		break;
	case LOAD_MESH_DATA_ERROR:
		std::cout << "Load mesh data error: " << std::endl;
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