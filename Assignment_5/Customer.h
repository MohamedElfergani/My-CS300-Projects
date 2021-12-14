// start time
//arrival time
//proccessing time
#ifndef CUSTOMER
#define CUSTOMER
#include <vector>
#include <iostream>

using namespace std;

class Customer
{

private:
    int arrivalTime;     // the time when customers arrive
    int startTime;       // time when customer starts
    int transactionTime; // time taken for transaction
    int departureTime; 
public:
    Customer();                                          // constructor
    Customer(const int _arrive, const int _transaction); // copy constructor with two integers as param
    Customer(const Customer &other);
    ~Customer();

    //getter methods
    int getArrivalTime() const;
    int getStartTime() const;
    int getDepartureTime() const;
    int getTransactionTime() const;

    //setter methods
    void setArrivalTime(const int);
    void setStartTime(const int);
    void setDepartureTime(const int);
    void setTransactionTime(const int);
};

/* ------------------------------ CONSTRUCTOR, COPY CONSTRUCTOR, COPY ASSIGNMENT, DESTRUCTOR ---------------------------------------*/
Customer::Customer() : arrivalTime(0), startTime(), transactionTime(0), departureTime(startTime + transactionTime) {}

Customer::Customer(const int _arrive, const int _transaction) : startTime(0), arrivalTime(_arrive), transactionTime(_transaction), departureTime (startTime + transactionTime) {}

Customer::Customer(const Customer &other)
{
    *this = other;
}

Customer::~Customer() {}

/* ------------------------------ ACCESSORS ---------------------------------------*/
int Customer::getArrivalTime() const
{
    return arrivalTime;
}

int Customer::getStartTime() const
{
    return startTime;
}

int Customer::getTransactionTime() const
{
    return transactionTime;
}

int Customer::getDepartureTime() const 
{
    return departureTime; 
}

/* ------------------------------MODIFIERS ---------------------------------------*/
void Customer::setArrivalTime(const int _myArriveT)
{
    arrivalTime = _myArriveT;
}

void Customer::setStartTime(const int _myStart)
{
    startTime = _myStart;
}

void Customer::setTransactionTime(const int _transTime)
{
    transactionTime = _transTime;
}

void Customer::setDepartureTime(const int _myDepart)
{ 
    departureTime = _myDepart;
}
#endif