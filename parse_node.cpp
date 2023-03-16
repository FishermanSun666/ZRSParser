#include "parse_node.h"

void ParseNode::Parse(std::stringstream& input) {
	std::string buffer;
	while (std::getline(input, buffer)) {
		if ("" == buffer) { continue; }
		size_t pos1 = buffer.find('(');
		size_t pos2 = buffer.find(')');
		if (pos1 != std::string::npos) {
			std::string tmp = buffer.substr(0, pos1);
			tmp = RemoveChar(' ', tmp);
			ParseNode* children = new ParseNode(RemoveChar('\t', tmp));
			if (std::string::npos == pos2) { //No ')' to find the next node to read
				children->Parse(input);
			}
			else {
				tmp = buffer.substr(pos1 + 1, pos2 - pos1 - 1);
				children->context = RemoveChar('"', tmp);
			}
			childrens.push_back(children);
		}
		else {
			return;
		}
	}
}

void ParseNode::PrintNode(int level) {
	std::cout << std::string(level, '\t') << type << ":" << context << std::endl;
	for (auto child : childrens) {
		child->PrintNode(level + 1);
	}
}