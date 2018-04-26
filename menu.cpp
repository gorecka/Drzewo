#include "menu.hpp"

void Menu::display(string data1, string data2, int term) {   
		if(term == 0){ // Drzewo sortowane po tytu³ach
		cout << "Tytul: " << data1 << " |  Autor: " << data2 << endl;
		cout << "------------------------------------------------------------------------------" << endl;
		}
		else
		if(term == 1){ //drzewo sortowane po autorach
			cout << "Autor: " << data1 << " |  Tytul: " << data2 <<endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}
	}
void Menu::displayAll(Tree<string>* current) {
		if(current->left) {
            displayAll(current->left);
		}
		display(current->data1, current->data2, current->configuration);
		if(current->right) {
            displayAll(current->right);
		}
    }
void Menu::control() {
        Read read;
    	Tree<string>* titleCollection = read.readFromFile(0);
    	Tree<string>* nameCollection = read.readFromFile(1);
    	while(1){
    		int choice;
    		cout << "Co chcesz zrobic?" << endl;
    		cout << "1 - wyswietl kolekcje posortowana tytulami" << endl;
    		cout << "2 - wyswietl kolekcje posortowana autorami" << endl;
    		cout << "3 - wyszukaj wszystkie dziela autora" << endl;
    		cout << "4 - dodaj dzielo" <<endl;
    		cout << "5 - usun dzielo" << endl;
    		cout << "6 - wyszukaj dzielo" << endl;
    		cout << "7 - wyjscie" << endl << endl;
    		cin >> choice;

    		if(cin.fail()) {
    			cout << "Powinienes wprowadzic liczbe" << endl;
    			cin.clear();
    			cin.ignore();
    			continue;
			}
			cin.ignore();
    		switch(choice){
    		case 1: {  //wyswietlanie po tytulach
    			displayAll(titleCollection->root);
    			break;
			}
			case 2: {  //wyswietlanie po autorach
				displayAll(nameCollection->root);
				break;
			}
			case 3: {   //wyszukiwanie po autorze
				string name;
				while(1){
				cout << "Podaj autora" << endl;
				getline(cin, name);
				if(cin.fail()) {
    				cout << "Niepoprawnie wprowadzony autor" << endl;
    				cin.clear();
    				cin.ignore();
    				continue;
				}
				break;
				}
				cout << "Wyniki wyszukiwania to: "<<endl;
				nameCollection->find(nameCollection->root, name, 1);
				break;
			}
			case 4: {   //dodawanie dziela
				string title, name;
				while(1){
				cout  << "Podaj tytul dziela" << endl;
				getline(cin, title);
				if(cin.fail()) {
    				cout << "Niepoprawnie wprowadzony tytul" << endl;
    				cin.clear();
    				cin.ignore();
    				continue;
				}
				while(1){
				cout <<"Podaj autora" << endl;
				getline(cin, name);
				if(cin.fail()) {
    				cout << "Niepoprawnie wprowadzony autor" << endl;
    				cin.clear();
    				cin.ignore();
    				continue;
				}
				break;
				}
				break;
				}
				titleCollection->addLeaf(titleCollection->root, new Tree<string>(title, name, 0));
				nameCollection->addLeaf(nameCollection->root, new Tree<string>(name, title, 1));
				break;
			}
    		case 5: {   //uwuwanie dziela
    			string title, name;
    			while(1){
    			cout << "Podaj tytul dziela do usuniecia"<<endl;
    			getline(cin, title);
    			if(cin.fail()) {
    				cout << "Niepoprawnie wprowadzony tytul" << endl;
    				cin.clear();
    				cin.ignore();
    				continue;
				}
				break;
				}
				while(1) {
				cout << "Podaj autora dziela" << endl;
				getline(cin, name);
				if(cin.fail()) {
    				cout << "Niepoprawnie wprowadzony autor" << endl;
    				cin.clear();
    				cin.ignore();
    				continue;
				}
				break;
				}
				titleCollection->removeNode(titleCollection, title, name);
				nameCollection->removeNode(nameCollection, name, title);
				break;
			}
			case 6:{   //wyszukiwanie dziela
				string title;
				while(1){
					cout << "Podaj tytul dziela" << endl;
					getline(cin, title);
					if(cin.fail()) {
    					cout << "Niepoprawnie wprowadzony tytul" << endl;
    					cin.clear();
    					cin.ignore();
    					continue;
					}
					break;
					}
					cout << "Wyniki wyszukiwania to: "<<endl;
					titleCollection->find(titleCollection, title, 0);
				break;
			}
			case 7:{  //wyjscie
				titleCollection->removeTree(titleCollection);
				titleCollection->removeTree(nameCollection);
				return;
			}
			default: {
				cout << " Wybierz opcje z menu" << endl;
				break;
			}
    		}
    	}

	}

