#ifndef READ_HPP
#define READ_HPP
#include "tree.hpp"
#include <fstream>
#include "painting.hpp"

class Read {
	public:
	Tree<Painting>* readFromFileTitle();  //wszytywanie do drzewa sortowanego po tytule
	Tree<Painting>* readFromFileAuthor(); //wszytywanie do drzewa sortowanego po autorze
	
};

#endif
