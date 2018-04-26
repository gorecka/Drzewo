#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>


using namespace std;
template<typename T>
struct Tree {
	int configuration; //jesli 0 to pierwszy tytul, jesli 1 to pierwszy autor
	T data1;
	T data2;
	struct Tree* root; // wska�nik na korze�
	struct Tree* left;	//wska�nik na w�ze� na lewo
	struct Tree* right; // wska�nik na w�ze� na prawo
	struct Tree* parent; // wska�nik na rodzica
	Tree(T data1, T data2, int configuration) {
		this->parent = NULL;	//wskaznik na rodzica
		this->data1 = data1;	//wedlug tych danych sortowane drzewo
		this->data2 = data2;	
		this->left = NULL; 		//wskaznik na lewe dziecko
		this->right = NULL; 	//wskaznik na prawe dziecko
		this->configuration = configuration; 	//mowi czy drzewo posortowane po tytulach, czy autorach
		this->root = this;
	} 
	Tree(T data1, T data2, int configuration, Tree* root) {
		this->parent = NULL;
		this->data1 = data1;
		this->data2 = data2;
		this->left = NULL;
		this->right = NULL;
		this->configuration = configuration;
		this->root = root;
	}  
	
	bool find(Tree *now, T data1, int counter) { //obecnie por�wnywane drzewo i dane szukane
		if(now->data1 == data1){
			counter = counter + 1;
			cout << now->data1 <<"  " << now->data2<<endl;
			if(now->left){
			find(now->left, data1, counter);  //taka sama warto�� mo�e wyst�pi� tylko z lewej strony
			}  
			else return counter;                      
			}
		else{	
		if(now->data1 > data1) {
			if(now->left){
			find(now->left, data1, counter);
		}
			else {
			if(counter == 0){
			cout << "Nie ma elementu spelniajacego warunek" << endl;
			return false;
			}	
			return counter;
			}
		}
		else {
			if(now->right){
			find(now->right, data1, counter);
			}
			else
			if(counter == 0){
			cout << "Nie ma elementu spelniajacego warunek" << endl;
			}
			return counter;
			}
		}
	} 
	Tree* addLeaf(Tree *now, Tree *leaf) { //szukamy miejsca gdzie wstawic nowy w�ze�  Tree*
		if(now->data1 >= leaf->data1) {  //elementy mniejsze b�dz r�wne umieszczamy na lewo
			if(!(now->left)) {
				now->left = leaf;
				leaf->parent = now;
				return now->root;
			}
			else 
			addLeaf(now->left, leaf); 
		}
		else{   //elementy wi�ksze ustawiamy na prawo
			if(!(now->right)){
				now->right = leaf;
				leaf->parent = now;
				return now->root;
			}
			else
			addLeaf(now->right, leaf);
		}	
	}  
	Tree* removeNode(Tree *now, T data1, T data2) { // usuwamy wybrany weze� z danymi
		Tree* helper = NULL;
		Tree* temp = NULL;
		if((now->data1 == data1) && (now->data2 == data2)){
			if(now->parent){ //usuwamy elementy, ktore nie sa korzeniem
				if(!(now->left)){                      //usuwamy element bez dzieci 
					if(!(now->right)){
						if(now->parent->left == now){
							now->parent->left = NULL;
						}
						else{
							now->parent->right = NULL;
						}
						temp = now->parent;
						delete now;
						return temp->root;
					}
				}
				else{
				if(now->parent->left == now) {
					if(now->left){
						helper = now->left;						          //dok�adamy ca�� ga���
						now->parent->left = NULL;
						if(now->right){
							temp = now->right;
						}							          
						delete now;
						addLeaf(helper->root, helper);
						if(temp){
							addLeaf(temp->root, temp);
						}
						return helper->root;
					}
					else {
						if(now->right) {
							temp = now->right;
							temp->parent = now->parent;
							now->parent->left = temp;
							delete now; 
							return temp;
						}
					
						
					}
				}
				else{
					if(now->left) {
						helper = now->left;
						temp = NULL;
						if(now->right) {
							temp = now->right;
						} 
						now->parent->right = NULL;
						delete now;
						addLeaf(helper->root, helper);
						if(temp) {
							addLeaf(temp->root, temp);
						}
						return helper->root;
					}
					else {
						if(now->right) {
							temp = now->right;
							temp->parent = now->parent;
							now->parent->right = temp;
							now->right = NULL;
							delete now;
							return temp->root;
						}
					
					}
				}
			}
		}
			else { //gdy usuwamy element ktory jest korzeniem
				if(now->left) {	//lewe dziecko zostaje nowym korzeniem
					Tree* newRoot = now->left;
					Tree* temp = NULL;
					newRoot->parent = NULL;
					newRoot->root = newRoot;
					if(now->right){
						temp = now->right;
					}
					setNewRoot(now, newRoot);  //ustawiamy nowy korzen wszystkim elementom
					now->left = NULL;
					delete now;
					if(temp) {
						addLeaf(newRoot, temp); //ustawiamy na nowo elementy, ktore wczesniej byly z prawej strony korzenia
					}
				
				
				}
				else {
					if(now->right) {    //korzen nie ma dzieci z lewej
						Tree* temp = now->right;
						temp->parent = NULL;
						setNewRoot(now, temp);  
						now->right = NULL;
						delete now;
					}
					else
					delete now;
				}
			}
		}

		
		else{
			if(now->data1 >= data1) {  //przechodzimy drzewo, �eby znale�� element do usuni�cia
				if(now->left) {
					removeNode(now->left, data1, data2);
				}
				}
			else{
				if(now->right) {
					removeNode(now->right, data1, data2);
				}
				else
				cout << "Taki element nie istnieje" << endl;
				}
			}
		
		}	
	bool removeTree(Tree *now)  {
		if(now->left) {
            removeTree(now->left);
		}
		if(now->right) {
            removeTree(now->right);
		}
		delete(now);
		return true;
	}  
	Tree* setNewRoot (Tree* now, Tree* root){
		if(now->left) {
            setNewRoot(now->left, root);
		}
		now->root = root;
		cout << now->root->data1 <<endl;
		if(now->right) {
			
            setNewRoot(now->right, root);
		}
		return now;
	} 
};

#endif				
