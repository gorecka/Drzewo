#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <iostream>
#include "tree.hpp"
#include "read.hpp"



class Menu {
	public:
	void display(string data1, string data2, int term);   //wyswietlanie elementu
	void displayAll(Tree<string>* current); 	//wyswietlanie calego drzewa
    void control();		//menu uzytkownika
};


#endif
