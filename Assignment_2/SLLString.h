#ifndef SLLString_1
#define SLLString_1
#include <iostream>
#include "Node.h"





class SLLString {

private:
	std::string s;
	Node* head;

public:

	SLLString(); //Default constructor
	
	SLLString(const std::string& other); //copy constructor taking a C++ string as parameter. 
	
	~SLLString(); // destructor fixed
	
	SLLString(const SLLString& other); //copy constructor taking another SLLString 
	
	SLLString& operator = (const SLLString& other); // assignment constructor 
	
	int length() const; // get length of this string. 
	
	SLLString& operator += (const SLLString& other); // concatenation 
	
	char& operator[](const int n) const; //get character at index n. done
	
	int findSubstring(const SLLString& substring); // done find the index of the first occurrence of substring in the current string. Returns -1 if not found.
	
	int findSubstring(std::string s); // takes in c++ string and finds it in the current object.
	
	void erase(char c); //erase the chosen letter from the SLLString
	
	friend std::ostream& operator << (std::ostream& out, SLLString& s);
	

};


#endif // !SLLString_1