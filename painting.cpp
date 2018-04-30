#include "painting.hpp"

Painting::Painting(string title, string author) 
	: title(title), author(author) {
	}

string Painting::getAuthor() {
	return author;
}

string Painting::getTitle() {
	return title;
}
