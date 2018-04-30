#include "tests.hpp"

void Tests::testRead (){ //czy wszytywanie z pliku dziala
			Read read;
			if(!(read.readFromFileTitle()))
			throw "wszytywanie z pliku nie dziala";
		}
void Tests::testFind() { //czy funkcja wyszukujaca dziala poprawnie
			Painting painting("Tytul", "Autor");
			Tree<Painting>* testCollection = new Tree<Painting>(painting);
			Painting painting1("Kolejny", "Kogos");
			Tree<Painting>* Element = new Tree<Painting>(painting1, testCollection);
			testCollection->addLeaf(testCollection, Element);
			PaintingController paintingController;
			vector<Painting> result;
			paintingController.search("Tytul", testCollection, result);
			testCollection->removeTree(testCollection);
			if(result[0].getTitle() != "Tytul") {
				throw "wyszukiwanie nie dzial";
			}
		}
void Tests::testRemove() {   //Czy poprawnie usuwa podany element
			Painting painting("Tytul", "Autor");
			Tree<Painting>* testCollection = new Tree<Painting>(painting);
			Painting painting1("Kolejny", "Kogos");
			Tree<Painting>* Element = new Tree<Painting>(painting1, testCollection);
			testCollection->addLeaf(testCollection, Element);
			Painting painting2("Alabaster", "Jakis aktor");
			Tree<Painting>*Element1 = new Tree<Painting> (painting2, testCollection);
			testCollection->addLeaf(testCollection, Element1);
			testCollection->removeNode(testCollection, painting2);
			PaintingController paintingController;
			vector<Painting> result;
			paintingController.search("Alabaster", testCollection, result);
			result.push_back(painting);
			if(result[0].getTitle() == "Alabaster") {
				throw "usuwanie nie dziala"; 
			}	
		}
