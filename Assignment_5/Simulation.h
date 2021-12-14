#ifndef SIMULATION
#define SIMULATION
#include <vector>
#include <fstream>
#include "Customer.h"
#include "ArrayQueue.h"

using namespace std;

class Simulation
{

private:
    ArrayQueue<Customer> *CustomerQueue;
    double avgWaitTime;
    int maxWaitTime;
    int currentTime;

public:
    Simulation();
    ~Simulation();
    void processCustomers(vector<Customer>);
    void printStatistics();
};

/* ------------------------------ CONSTRUCTOR, DESTRUCTOR ---------------------------------------*/
Simulation::Simulation() : avgWaitTime(-1), maxWaitTime(-1), currentTime(0)
{
    CustomerQueue = new ArrayQueue<Customer>();
}

Simulation::~Simulation()
{
    //delete CustomerQueue and set it to NULL
    delete CustomerQueue;
    CustomerQueue = NULL;
}

/* ------------------------------ PROCESS CUSTOMERS, PRINT STATISTICS ---------------------------------------*/
void Simulation::processCustomers(vector<Customer> allCus)
{
    if (allCus.size() == 0)
    {
        return;
    }
    ArrayQueue<Customer> CustomerQueue;
    int timePassed = 0;
    int timeArrived = 0;
    int waitTime = 0;
    int totalWaitTime = 0;

    for (int i = 0; i < allCus.size(); i++) // for loop
    {
        CustomerQueue.enqueue(allCus.at(i));
    }

    int count; // make a new integer named count 
    count = CustomerQueue.getCount(); // customerQueue access getCount and set it equal to count

    for (int j = 0; j < count; j++) // for loop 
    {
        timeArrived = allCus[j].getArrivalTime(); // set timeArrived to maek allCus access getArrivedTime
        waitTime = timePassed - timeArrived; // get waitTime by substracting 
        if (waitTime > maxWaitTime) // if statement 
        {
            maxWaitTime = waitTime;
        }
        totalWaitTime += waitTime; // adds the right result of totalWiatTime to waitTime
        timePassed += allCus[j].getTransactionTime(); // allCus access getTransactionTime and set it equal to timePassed 
        CustomerQueue.dequeue();
    }
    // totalWaitTime / by count is the average wait time
    avgWaitTime = (double)totalWaitTime / count;
}

void Simulation::printStatistics()
{
    cout << "Max Delay: " << maxWaitTime << endl;
    cout << "Average Delay: " << avgWaitTime << endl;
}
#endif