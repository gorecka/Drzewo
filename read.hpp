#ifndef READ_HPP
#define READ_HPP
#include "tree.hpp"
#include <fstream>

class Read {
	public:
	Tree<string>* readFromFile(int term); //{  
	/*	fstream file;
		file.open("artist.txt");
		string title, name;
		Tree<string>* Collection;
		if(term == 0) {
			getline(file, title);
			getline(file, name);
			Collection = new Tree<string>(title, name, 0);
			while(!file.eof()){
				getline(file, title);
				getline(file, name);
				Tree<string>* Element = new Tree<string>(title, name, 0, Collection);
				Collection->addLeaf(Collection, Element);
			}	
		} 
		else{
			getline(file, title);
			getline(file, name);
			Collection = new Tree<string>(name, title, 1);
			while(!file.eof())	{
				getline(file, title);
				getline(file, name);
				Tree<string>* Element = new Tree<string>(name, title, 1, Collection);
				Collection->addLeaf(Collection, Element);
			}	
		}
		file.close();
		return Collection;
	} */
	
};

#endif
