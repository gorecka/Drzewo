#include <iostream>
#include <string>
#include "tree.hpp"
#include "read.hpp"
#include "menu.hpp"
#include "tests.hpp"
#include "painting.hpp"
#include "paintingcontroller.hpp"


int main() {
	Tests test;
	try {
	test.testFind();
	test.testRead();
	test.testRemove();  //przy poprawnym dzialaniu funkcji wyswietli sie komunikat "Nie ma elementu spelniajacego warunek" co pokazuje, ze usunieto podany element
	}
	catch (const char * a) {
		cout << "Testy znalazly blad" << endl;
	}
	cout << "Witaj" << endl;
	Menu menu;
	menu.control();
	return 0;
}
