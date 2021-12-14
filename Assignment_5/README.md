Assignment5
Event Driven Simulation
Due Date: Dec 3, 2021 11:59pm

TASK
In this assignment, you’ll develop an event driven simulation to simulate the arrival  and 
processing of customers at a bank with one teller, and compute some statistics, such as 
the average wait time of customers and maximum wait time of a customer.  The bank 
can use these statistics to determine whether it makes sense to hire another teller. 
This assignment will help you get practice with: 
 Reading from a file
 Queue implementations
 Event driven simulations
Customers arrive at the bank in some order. For each customer number i, assume that 
you know the time when they arrived Ti and the duration  Di it takes the bank teller to 
help the customer . The teller helps the customers in the order of their arrival. If the 
teller started to help a customer i,  he continues  to help that customer until the 
customer’s work finished. The duration for helping customer  i takes exactly Di minutes.
We can assume that if a customer j arrives while the teller is helping customer i, 
customer j enters a queue (also called a line). Figure 13.6 ( c)  in your text (shown below) 
shows the situation with two customers, one currently being served by a teller and the 
other one waiting in line.


We can make the simplifying assumption that the queue in the bank can hold 100 
customers, and that at no time will there be more than 100 customers at the bank. 
Please note that although multiple customers could arrive at the same time, they still 
must come through the single queue in a certain order. In this assignment, we assume 
the order is already known and specified in the input data. The teller helps the next 
available customer from the queue as soon as he finishes helping  the previous one. If 
there are no customers in the queue, the teller stays idle. 
You are asked to write a C++ program to simulate this process. You’ll read customers, 
their arrival times, and their durations at the teller as inputs to your program. Here is 
the input format:
 The first line of the input contains the number n of incoming customers. 
 Each of the next n lines contains two numbers. ith line contains the time of arrival 
Ti  of the customer i and the duration Di  it takes the teller to help customer i.
 Assume those n lines are already sorted in terms of the time of arrival Ti so the 
computer will process these customers in the order specified by the input, even 
if two customers arrive at the same time.
 All the numbers in the input are non-negative integers.