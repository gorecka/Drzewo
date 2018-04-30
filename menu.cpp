#include "menu.hpp"

void Menu::display(Painting painting) {   
		printf("%-20s | %s\n", painting.getTitle().c_str(), painting.getAuthor().c_str());
		cout << "-----------------------------------------------------------------" << endl;
	}
void Menu::displayAll(Tree<Painting>* current) {
		if(current->left) {
            displayAll(current->left);
		}
		display(current->data1);
		if(current->right) {
            displayAll(current->right);
		}
    }
void Menu::control() {
        Read read;
        PaintingController paintingController;
    	Tree<Painting>* titleCollection = read.readFromFileTitle();
    	Tree<Painting>* nameCollection = read.readFromFileAuthor();
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
    			cout << "-----------------------------------------------------------------" << endl;
    			printf("%-20s | %s\n", "Tytul", "Autor");
				cout << "-----------------------------------------------------------------" << endl;
    			displayAll(titleCollection);
    			break;
			}
			case 2: {  //wyswietlanie po autorach
				cout << "-----------------------------------------------------------------" << endl;
				printf("%-20s | %s\n", "Autor", "Tytul");
				cout << "-----------------------------------------------------------------" << endl;
				displayAll(nameCollection);
				break;
			}
			case 3: {   //wyszukiwanie po autorze
				string name;
				vector<Painting> result;
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
				cout << "Wyniki wyszukiwania to: "<<endl << endl;
				PaintingController Controller;
				paintingController.search(name, nameCollection, result);
				cout << "-----------------------------------------------------------------" << endl;
				printf("%-20s | %s\n", "Autor", "Tytul");
				cout << "-----------------------------------------------------------------" << endl;
				for(int i = 0; i < result.size(); i++) {
					printf("%-20s | %s\n", result[i].getTitle().c_str(), result[i].getAuthor().c_str());
					cout << "-----------------------------------------------------------------" << endl;
				}
				cout << endl;
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
				Painting paintingTitle(title, name);
				titleCollection->addLeaf(titleCollection, new Tree<Painting>(paintingTitle));
				Painting paintingAuthor(name, title);
				nameCollection->addLeaf(nameCollection, new Tree<Painting>(paintingAuthor));
				break;
			}
    		case 5: {   //usuwanie dziela
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
				Painting paintingTitle(title, name);
				Painting paintingAuthor(name, title);
				titleCollection->removeNode(titleCollection, paintingTitle);
				nameCollection->removeNode(nameCollection, paintingAuthor);
				break;
			}
			case 6:{   //wyszukiwanie dziela
				string title, author;
				vector<Painting> result;
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
					cout << "Wyniki wyszukiwania to: "<<endl<< endl;
					PaintingController paintingController;
					paintingController.search(title, titleCollection, result);
					cout << "-----------------------------------------------------------------" << endl;
					printf("%-20s | %s\n", "Tytul", "Autor");
					cout << "-----------------------------------------------------------------" << endl;
					for(int i = 0; i < result.size(); i++ ) {
						printf("%-20s | %s\n", result[i].getTitle().c_str(), result[i].getAuthor().c_str());
						cout << "-----------------------------------------------------------------" << endl;
					}
					cout << endl;
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

