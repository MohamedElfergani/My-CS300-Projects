#include "SLLString.h"

//we overload the operator 
std::ostream& operator << (std::ostream& out, SLLString& s) {
	Node* lead = s.head;
	while (lead != nullptr) {
		out << lead->data;
		lead = lead->nextNode;
	}
	return out;

}
SLLString::SLLString() { //default constructor 

	// initalize a node 
	head = new Node('\0', nullptr);

}

//we copy this constructor while taking a C++ string
SLLString::SLLString(const std::string& other) {
	head = new Node('\0', nullptr);
	Node* n = head;
	for (int i = 0; i < other.length(); i++) {
		if (i == other.length()) {
			n->nextNode = new Node(other[i], nullptr);
		}
		n->nextNode = new Node(other[i], nullptr);
		n = n->nextNode;

	}
}


// destructor fixed
SLLString::~SLLString() {
	Node* p = head->nextNode;
	delete head;
	while (p != nullptr) {
		Node* previous = p;
		p = p->nextNode;
		delete previous;

	}
}

//copy constructor
SLLString::SLLString(const SLLString& other) {
	head = new Node('\0', nullptr);
	Node* t = head;
	Node* s = other.head;

	while (s != nullptr) {
		if (s->nextNode != nullptr) {
			Node* next = new Node('\0', nullptr);
			t->nextNode = next;
			t->data = s->data;
			t = next;

		}
		else {
			s = s->nextNode;
		}
		t->nextNode = nullptr;
	}

}

int SLLString::length() const {
	int count;
	count = 0;

	Node* lead = this->head;
	while (lead->nextNode) {
		count++;
		lead = lead->nextNode;
	}
	return count;

}

// assignment constructor
SLLString& SLLString::operator = (const SLLString& other) {

	//input string node
	Node* mySecondNode = other.head;
	Node* nextFirst = mySecondNode->nextNode;
	Node* firstNode = head->nextNode;

	firstNode = new Node(nextFirst->data, nullptr);
	head->nextNode = firstNode;

	while (nextFirst) {
		if (nextFirst->nextNode == nullptr) {
			break;
		}

		nextFirst = nextFirst->nextNode;
		firstNode->nextNode = new Node(nextFirst->data, nullptr);
		firstNode = firstNode->nextNode;
	}


	return *this;
}

// concatenation  
SLLString& SLLString:: operator+= (const SLLString& other) {
	// new nodes 
	Node* firstLead = this->head->nextNode;
	Node* secondLead = other.head->nextNode;

	// while loop untill the string ends
	while (firstLead->nextNode) {
		firstLead = firstLead->nextNode;
	}

	// while loop while adding a new node 
	while (secondLead->nextNode) {
		Node* thisData = new Node(secondLead->data, nullptr);
		firstLead->nextNode = thisData;
		firstLead = firstLead->nextNode;
		secondLead = secondLead->nextNode;
	}

	Node* endOfData = new Node(secondLead->data, nullptr);
	firstLead->nextNode = endOfData;
	return *this;

}





//  find the index of the first occurrence of substring in the current string. Returns -1 if not found.
int SLLString::findSubstring(const SLLString& substring) {
	int pStrLength = substring.length();

	//checks how many numbers of the right chars are in substring
	// start with value of 0 
	int charNum = 0;

	//flag for finding first char of substring within
	// started with false to make sure it has a value
	bool getFirstLetter = false;

	// get the index place
	int firstCounter = 0;

	//returns this variable 
	int firstIndex;


	Node* thisFirst = this->head->nextNode;
	while (thisFirst->nextNode != nullptr) {

		// if statement to make it continue when the first node's index is = 0 
		if (thisFirst == this->head->nextNode) {
			thisFirst = thisFirst->nextNode;
			continue;
		}

		firstCounter++;

		//found first letter
		if (thisFirst->data == substring.operator[](0)) {
			getFirstLetter = true;
			charNum++;
			firstIndex = firstCounter;
		}

		//check the letters and check if they match 
		if (getFirstLetter == true) {
			for (int i = 1; i < pStrLength; i++) {
				thisFirst = thisFirst->nextNode;
				if (thisFirst->data == substring.operator[](i)) {
					charNum++;
				}
			}

			// return firstIndex if the whole substring was found
			if (charNum == pStrLength) {
				return firstIndex;
			}

		}
		else {
			thisFirst = thisFirst->nextNode;
		}
	}
	return -1; // returns -1 as requested 
}

//get character at index n. 
char& SLLString::operator[](const int n) const {
	Node* lead = head->nextNode;

	for (int i = 0; i < n; i++) {
		lead = lead->nextNode;
	}
	return lead->data;
}

// takes in c++ string and finds it in the current object.
int SLLString::findSubstring(std::string s) {
	return findSubstring(SLLString(s));
}

//erase the chosen letter from the SLLString  
void SLLString::erase(char c) {
	Node* thisFirst = this->head->nextNode;
	Node* prevElement;

	while (thisFirst->nextNode != nullptr) {
		if (thisFirst->nextNode->data == c) {

			//saves the node we're in
			prevElement = thisFirst;

			//saves the nodes matching together
			Node* rightElement = thisFirst->nextNode;
			prevElement->nextNode = rightElement->nextNode;


			if (prevElement->data == c) {
				continue;
			}
		}


		else {
			thisFirst = thisFirst->nextNode;
		}
	}

}