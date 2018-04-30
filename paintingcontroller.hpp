#ifndef PAINTINGCONTROLLER_HPP
#define PAINTINGCONTROLLER_HPP

#include "painting.hpp"
#include "tree.hpp"

class PaintingController{    
public:      
	Tree<Painting>* search(string data, Tree<Painting>* now, vector<Painting> &result, int counter = 0); //wyszukiwanie dziela po tytule lub wszystkich dziel autora
		
};

#endif
