#include "read.hpp"

Tree<Painting>* Read::readFromFileTitle() {  
		fstream file;
		file.open("artist.txt");
		string title, name;
		Tree<Painting>* Collection;
		getline(file, title);
		getline(file, name);
		Painting painting(title, name);
		Collection = new Tree<Painting>(painting);
		while(!file.eof()){
			getline(file, title);
			getline(file, name);
			Painting painting(title, name);
			Tree<Painting>* Element = new Tree<Painting>(painting, Collection);
			Collection->addLeaf(Collection, Element);
		}	
		file.close();
		return Collection->root;
	}
	
Tree<Painting>* Read::readFromFileAuthor() {
	fstream file;
	file.open("artist.txt");
	string title, name;
	Tree<Painting>* Collection;
	getline(file, title);
	getline(file, name);
	Painting painting(name, title);
	Collection = new Tree<Painting>(painting);
	while(!file.eof())	{
		getline(file, title);
		getline(file, name);
		Painting painting(name, title);
		Tree<Painting>* Element = new Tree<Painting>(painting, Collection);
		Collection->addLeaf(Collection, Element);
	}
	file.close();
	return Collection->root;	
}
