#include "tests.hpp"

void Tests::testRead (){
			Read read;
			if(!(read.readFromFile(1)))
			throw "wszytywanie z pliku nie dziala";
		}
void Tests::testFind() {
			Tree<string>* testCollection = new Tree<string>("Tytul", "Autor",0);
			Tree<string>* Element = new Tree<string>("Kolejny", "Kogos", 0, testCollection);
			testCollection->addLeaf(testCollection, Element);
			int value = (testCollection->find(testCollection->root, "Tytul", 0));
			testCollection->removeTree(testCollection->root);
			if(value == 0) {
				throw "wyszukiwanie nie dzial";
			}
		}
void Tests::testRemove() {
			Tree<string>* testCollection = new Tree<string>("Tytul", "Autor",0);
			Tree<string>* Element = new Tree<string>("Kolejny", "Kogos", 0, testCollection);
			Tree<string>*Element1 = new Tree<string> ("Alabaster", "Aktor", 1, testCollection);
			if(!(testCollection->removeTree(testCollection->root)))
			throw "usuwanie nie dziala"; 
			
		}
