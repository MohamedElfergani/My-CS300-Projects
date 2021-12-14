Assignment1 
Bag Class Abstraction
 
 
Due Date: October 15, 2021 11:59pm 
 
Purpose: This assignment will help you get practice with:  
• Abstract Data Types 
• Inheritance 
• Polymorphism 
• C++ pointers 
• C++ Classes 
• C++ virtual and pure virtual functions 
• C++ Class Templates 
• C++ Arrays 
 
TASK 
 
A container class is a data type that is capable of holding a collection of items and provides 
functions to access them. Bag is an example of a container class. It is an unordered collection of 
items that may have duplicates.  
In this assignment, you are asked to design and develop an abstract Bag class, called 
BagInterface, with the following fixed collection of operations: 
• insert an item of any type into a bag 
• query the bag contents: two queries 
o Is an item in the bag? 
o How many copies of an item is in the bag? 
• remove an item from the bag 
• clear the bag 
• get the size of the bag  
o How many items are there in the bag? 
• check if the bag is empty 
• check if the bag is full 
o Assume the bag capacity is 20 
 
 

In addition to BagInterface, you are asked to implement two classes of bag 
implementations: PlainBag and MagicChangeBag. PlainBag is a simple container that 
holds items of any type using an array implementation. MagicChangeBag is also very similar 
to PlainBag, with two exceptions. When an item is inserted into a magic change bag, it’ll 
magically disappear, and bag looks empty. Whenever a remove operation is invoked, all the 
items, except the one is removed will appear.   
 

TODO 
You are asked to: 
• create BagInterface abstract class 
• implement PlainBag and MagicChangeBag classes 
• use templates 
• use virtual and pure virtual functions 
• use arrays 
• provide UML class diagram for your solution 