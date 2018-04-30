#include "paintingcontroller.hpp"

Tree<Painting>* PaintingController::search(string data, Tree<Painting>* now, vector<Painting> &result, int counter) {
		if(now->data1.getTitle() == data){
			counter = counter + 1;
			result.push_back(now->data1);
			if(now->left){          //sprawdzamy czy w drzewie nie wystepuje tez inne drzewo autora, bedzie na lewo lub na prawo od wezla w zaleznosci od tytulu
			search(data, now->left,result, counter); 
			}  
			if(now->right) {
				search(data, now->right, result, counter);
			}
			else 	
			return now->root;    
			}
		else{						//szukamy wezla, ktory moze spelniac zalozenia
		if(now->data1.getTitle() > data) { 
			if(now->left){
			search(data, now->left, result, counter);
			}
			else {
			if(counter == 0){
			cout << "Nie ma elementu spelniajacego warunek" << endl;
			
			return now->root;
			}	
			return now->root; 
			}
		}
		else {
			if(now->right){
			search(data, now->right, result, counter);
			}
			else
			if(counter == 0){
			cout << "Nie ma elementu spelniajacego warunek" << endl;
			}
			return now->root;
			}
		}
	}
