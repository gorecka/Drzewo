#ifndef READ_HPP
#define READ_HPP
#include "tree.hpp"
#include <fstream>

class Read {
	public:
	Tree<string>* readFromFile(int term);
	
};

#endif
