#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <iostream>
#include "tree.hpp"
#include "read.hpp"
#include "painting.hpp"
#include "paintingcontroller.hpp"
#include <stdio.h>



class Menu {
	public:
	void display(Painting painting);   //wyswietlanie elementu
	void displayAll(Tree<Painting>* current); 	//wyswietlanie calego drzewa
    void control();		//menu uzytkownika
};


#endif
