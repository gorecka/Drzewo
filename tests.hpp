#ifndef TESTS_HPP
#define TESTS_HPP

#include "tree.hpp"
#include "menu.hpp"
#include "read.hpp"

class Tests {
	public:
		void testRead ();  //test wczytywania z pliku
		void testFind();	//test wyszukiwania
		void testRemove(); 	//test usuwania
};

#endif
