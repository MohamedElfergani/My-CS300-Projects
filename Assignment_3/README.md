Extensions of Link-based Stack
In this assignment, you will extend the link-based implementation of Stack. This Stack will support 3 
more additional functions:
1. T max() const;
This function always returns the maximum item value stored in this stack. It is not necessarily 
the item on the top of the Stack. It can be anywhere in the Stack. Your task is to implement this 
function efficiently such that it doesn’t need to traverse the whole linked list to find the max 
item for each call. Or in short, it runs in constant time.
2. T mean() const;
Like the above function, this function will return the average (mean) value of all items in this 
Stack. If the Stack holds integer data type, then this function will return the integer value using 
integer division. For example, the mean of 1 and 2 is (1+2)/2 = 1, while the mean of 1, 2, and 3 is 
(1+2+3)/3 = 2. Your task is to implement this function efficiently such that it doesn’t need to 
traverse the whole linked list to find the mean value. Or in short, it runs in constant time.
3. Stack<T> operator+(const Stack<T> &other);
This operator will zip two equal sized Stacks together while not breaking the above two 
functions. For example, given two Stacks implemented in linked list: 
Stack1: 4->3->2->1->NULL
Stack2: 5->6->7->8->NULL
Stack1 + Stack2 will be: 4->5->3->6->2->7->1->8->NULL where the new Stack will start with the 
top of Stack1, then it inserts the items from Stack2 and Stack1 alternatively like a zipper. 
Implementation and test:
You will extend the link-based implementation of Stack from the textbook. Make sure the sample code 
compiles and works before you proceed to the extensions. You can either design additional data 
structure to help you implement your functions or you can create additional member variables and 
helper functions. You don’t need to use any data structure or algorithms that we haven’t covered in 
class. 
There are two files provided: main.cpp and MyRand.h. 
 The MyRand.h file is an implementation of C++ random number generator, so that the results 
are consistent across all compilers.
 The main.cpp file includes all the test cases and auto-grading, so don’t modify it. It will 
automatically grade out of 40 points according to the correctness. So, you know exactly what 
you will get in that portion. Once you submit your assignment, you accept your final score for 
correctness.
 In the header portion of main.cpp, it #include a Stack.cpp and an Node.cpp file, which are what 
you need to implement by yourself in separate files. This is necessary for compiling template 
classes if the *.h and *.cpp are separate files. Alternatively, you can also put both the definition 
and the implementation of the template class in one *.h file. 
You don’t need to handle other edge cases.