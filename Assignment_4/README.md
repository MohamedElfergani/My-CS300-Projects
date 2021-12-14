Assignment4 
Big Integer Arithmetic and Doubly Linked Lists 125487541487989854659879745679874657942121354654  
+/-  
4239742897379701760298372870237459387520938475 
 
 
Due Date: November 19, 2021 11:59pm 
 
Important: You can work in a team of 2 students, or you can work individually in this 
assignment. If you choose to work as a group, you are supposed to email the names in 
the group to your instructor by Monday November 8th 12:00pm. If we don’t hear from 
you by this deadline, we’ll assume that you are going to work alone on the assignment. 
 
TASK 
You can represent an integer with any number of digits by storing the integer as a linked 
list of digits. In this assignment, you’ll design and implement a class for whole numbers 
arithmetic in which a number is implemented as a linked list of integers. You are asked 
to use doubly linked list as the internal data structure for the linked list of digits. 
 
 "423974289737970176029837287023745938752093" 
 
 
 4->2->3->9->7->4->2->8->9->7->3->7->9->7->0->1->7->6->0->2->9->8->3->7->2->8->7->0->2->3->7->4->5->9->3->8->7->5->2->0->9->3 
 
 
This assignment will help you get practice with:  
• Linked Lists 
• Doubly Linked List 
• Implementing iterator for a data structure 
• Working with really big integer numbers 
• Converting from string into a linked list of digits 
• Reading from a file 
 
Doubly Linked List 
A doubly linked list is a list that contains links to next and previous nodes. Unlike singly 
linked lists where traversal is only one way, doubly linked lists allow traversals in both 
ways. A generic doubly linked list node can be designed as:  

 Functional Requirements: 
1. Write a C++ class, a generic data type for doubly linked list data structure, 
namely DoublyLinkedList, that implements the following API: 
 
 
2. Design and implement BigInteger class that uses the doubly linked list 
implementation to represent big numbers. BigInteger class should overload 
the following functions: 
 
3. Throw the specified exception for the following corner cases: 
a. Create a IllegalArgumentException exception class and throw an 
IllegalArgumentException for a nun-numeric input to the 
constructor 
 
b. Create a NoSuchElementException class and throw an 
NoSuchElementException if the client calls next() and/or prev() 
method in the iterator when there are no more items to return 
 
4. A sample test.cpp file provided for you to test your implementation. Please make 
sure your implementation works with test.cpp and you run the tests before you 
submit your work. Please note that the total score after passing all test cases is 
40: 20 points for doubly linked list implementation + 20 points for Big Integer 
class implementation. The total point will be your final score for correctness of 
the assignment. 