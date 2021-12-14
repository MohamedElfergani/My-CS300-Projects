Assignment-2 
String as Singly Linked List 
 
Due Date: October 22, 2021 11:59pm 
 
Purpose: This assignment will help you get practice with:  
• Singly Linked Lists 
• C++ Rule of Big Tree (destructor. copy constructor. copy assignment operator) 
• C++ operator overloading  
• C++ pointers and reference variables 
 
TASK 
In many programming languages, the String class is typically implemented as an array of 
characters. Some other languages, such as Haskell, Erlang, and a few other functional 
programming languages, however, implement strings as Singly Linked List (SLL) of characters. 
Compared with the array implementations, the SLL ones are very easy for pattern matching 
because of the recursive structure of linked list. Let’s not worry about recursion in this 
assignment. 
In this assignment, you will implement a SLLString class using SLL. Your SLLString class will 
include the following members: 
• SLLString(); //Default constructor 
• SLLString(const string& other); //copy constructor taking a C++ string as parameter. 
• ~SLLString(); // destructor 
• SLLString(const SLLString& other); //copy constructor taking another SLLString 
• SLLString& operator=(const SLLString& other); // assignment constructor 
• int length(); // get length of this string 
• SLLString& operator+= (const SLLString& other); // concatenation 
• char& operator[](const int n); //get character at index n 
• int findSubstring(const SLLString& substring); // find the index of the first occurrence of 
substring in the current string. Returns -1 if not found 
• void erase(char c); //erase all occurrences of character c from the current string 
• support cout << operator 
• Node* head; // the head pointer to the SLL 
 
Each Node object should contain a char data type and a next pointer to Node.