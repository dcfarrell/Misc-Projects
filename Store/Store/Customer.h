#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Product.h"

class Customer {
	int id;
	char name[100];
	bool credit;
	double balance;
	char productsPurchased[5][100];
    int numPurchased;
    int size;
    static int counter; // declares but does not define
public:
    //int size;
    Customer(int customerID, const char name[], bool credit=false): id(customerID), credit(credit), balance(0.0), size(0) {setName(name); };
    int getID() const;
    const char* getName() const;
    void setName(char const customerName[]);
    bool getCredit() const;
    void setCredit(bool hasCredit);
    double getBalance() const;
    bool processPayment(double amount);
    bool processPurchase(double amount, Product product); 
    void outputRecentPurchases(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Customer& customer);

#endif
