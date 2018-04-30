#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include <cstdlib>



using namespace std;
template<class T>
struct Tree {
	T data1; //dane wprowadzane do drzewa
	struct Tree* root; // wskaŸnik na korzeñ
	struct Tree* left;	//wskaŸnik na wêze³ na lewo
	struct Tree* right; // wskaŸnik na wêze³ na prawo
	struct Tree* parent; // wskaŸnik na rodzica
	
	Tree(T data1) : data1(data1) {  //konstruktor korzenia
		this->parent = NULL;	//wskaznik na rodzica	
		this->left = NULL; 		//wskaznik na lewe dziecko
		this->right = NULL; 	//wskaznik na prawe dziecko
		this->root = this;
	} 
	
	Tree(T data1, Tree* root) :data1(data1) {  //konstruktor elementów innych niz korzen
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
		this->root = root;
	}  
	
	Tree* find(Tree *now, T data1, vector<T> &result, int counter = 0) { //funkcja wyszukujaca dany element drzewa
		if(now->data1 == data1){
			counter = counter + 1;
			result.push_back(now->data1);
			if(now->left){
			find(now->left, data1, result, counter);  //taka sama wartoœæ mo¿e wyst¹piæ tylko z lewej strony
			}  
			else 	
			return now->root;    
			}
		else{	
		if(now->data1 > data1) {
			if(now->left){
			find(now->left, data1, result, counter);
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
			find(now->right, data1, result, counter);
			}
			else
			if(counter == 0){
			cout << "Nie ma elementu spelniajacego warunek" << endl;
			}
			return now->root;
			}
		}
	}  
	Tree* addLeaf(Tree *now, Tree *leaf) { //szukamy miejsca gdzie wstawic nowy wêze³ 
		if(now->data1 >= leaf->data1) {  //elementy mniejsze b¹dz równe umieszczamy na lewo
			if(!(now->left)) {
				now->left = leaf;
				leaf->parent = now;
				return now->root;
			}
			else 
			addLeaf(now->left, leaf); 
		}
		else{   //elementy wiêksze ustawiamy na prawo
			if(!(now->right)){
				now->right = leaf;
				leaf->parent = now;
				return now->root;
			}
			else
			addLeaf(now->right, leaf);
		}	
		return now->root;
	}  
	Tree* removeNode(Tree *now, T data1) { // usuwamy wybrany weze³ z danymi
			Tree* helper = NULL;
			if(now->data1 > data1){  //szukamy odpowiedniego elementu
				if(now->left){
				now->left ->removeNode(now->left, data1);
				}
				else {
					cout << "Taki element nie istnieje" << endl;
				}
				return now->root;
			}
			else {
				if (now->data1 < data1) { //szukamy odpowiedniego elementu
					if(now->right) {
					now->right -> removeNode(now->right, data1);
					}
					else {
						cout << "Taki element nie istnieje" << endl;
					}
					return now->root;
				}
				else{
					if(now->right == NULL && now->left == NULL) { //element nie ma dzieci
						if(now->parent->left == now) {
							now->parent->left = NULL;
						}
						if(now->parent->right == now) {
							now->parent->right = NULL;
						}
						helper = now->parent->root;
						delete now;
						return helper;
					}
					else {
						if(now->right == NULL) {	//tylko dziecko na lewo
							helper = now;
							now = now->left;
							if(helper->parent->left == helper) {
								helper->parent->left = now;  
							}
							if(helper->parent->right == helper) {
								helper->parent->right = now;
							}
							delete helper; 
							return now->root;
						}
						else {
							if(now->left == NULL) { //tylko dziecko na prawo
								helper = now;
								now = now->right;
								if(helper->parent->left == helper) {
									helper->parent->left = now;
								}
								if(helper->parent->right == helper) {
									helper->parent->right = now;
								}
								delete helper;
								return now->root;
							}
							else { //element ma dwoje dzieci
								helper = findMax(now->left); //element usuwany zastepujemy najwiekszym elementem po lewej
								now->data1 = helper->data1;
								now->left->removeNode(now->left, helper->data1); 
								return now->root;
							}
						}
					}
				}
			}			
	}
	void removeTree(Tree *now)  {  //usuwanie calego drzewa
		if(now->left) {
            removeTree(now->left);
		}
		if(now->right) {
            removeTree(now->right);
		}
		delete now;
	}  

	Tree* findMax (Tree* now)  { //szukanie maksymalne wartosci w galezi
		while(now->right) {
			now = now->right;
		}
		return now;
	}
};

#endif				
