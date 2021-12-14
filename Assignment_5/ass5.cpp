#include <iostream>
#include <fstream>
#include "Customer.h"
#include "Simulation.h"
#include <vector>

using namespace std;

// read file from here
vector<Customer> readCustomers()
{
    vector<Customer> Main;               // create a new array of customer
    fstream myfile("data.txt", ios::in); //opens the file
    int count;                           // new int named count
    myfile >> count;                     // count is going to be assigned to the numbers inside the file
    int arrive, leave;                   // two new integers
    for (int i = 1; i <= count; i++)
    {
        myfile >> arrive >> leave;
        Main.push_back(Customer(arrive, leave));
    }
    myfile.close();
    return Main;
}

//please don't modify main function
int main()
{
    vector<Customer> customers = readCustomers(); //read list of customers and arrival times from a file
    Simulation s;
    cout << "Processing Customers:" << endl;
    s.processCustomers(customers); //simulates the teller serving the customers in the queue
    s.printStatistics();           // prints out the maxium delay and the average delay.
    return 0;
}
