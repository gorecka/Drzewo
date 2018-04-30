#ifndef  PAINTINGS_HPP
#define PAINTINGS_HPP
#include <string>
#include <iostream>

using namespace std;
class Painting {
	string title;
	string author;

	public: 
		Painting(string title,string author);		
		string getTitle();
		string getAuthor();
		
		
			
		bool operator==(Painting &p) const {
			if(this->title == p.getTitle()) {
				if(this->author == p.getAuthor()) {
					return true;
				}
				else
					return false;
				}
			else	
			return false;
		}
		
		bool operator >=(Painting &p) const {
			if(this->title == p.getTitle() && this->author >= p.getAuthor()) {
				return true;
			}
			if(this->title > p.getTitle()) {
				return true;
			}
			return false;
		}
		
		bool operator >(Painting &p) const {
			if(this->title > p.getTitle()) {
				return true;
			}
			else if(this->title == p.getTitle() && this->author > p.getAuthor()) {
				return true;
			}
			else
			return false;
		}
		bool operator <(Painting &p) const {
			if(this->title < p.getTitle()) {
				return true;
			}
			else 
			if(this->title == p.getTitle() && this->author < p.getAuthor() ) {
				return true;
			}
			else return false;
		}
};

#endif
