#include <iostream>
#include <string>
#include "tree.hpp"
#include "read.hpp"
#include "menu.hpp"
#include "tests.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Tests test;
	try {
	test.testFind();
	test.testRead();
	test.testRemove();
	}
	catch (const char * a) {
		cout << "Testy znalazly blad" << endl;
	}
	cout << "Witaj" << endl;
	Menu menu;
	menu.control();
	return 0;
}
