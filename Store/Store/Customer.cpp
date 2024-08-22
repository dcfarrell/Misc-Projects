#include <iostream>
#include <cstring>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

int Customer::counter = 0; // defines and initializes

int Customer::getID() const {
    return id;
}

const char* Customer::getName() const {
    return name;
}

void Customer::setName(char const customerName[]) {
    if (strlen(customerName) > 0) {
        strcpy(this->name, customerName);
    }
    else {
        counter++;
        ostringstream oss;
        oss << "Customer " << counter;
        strcpy(this->name, oss.str().c_str());
    }
}

bool Customer::getCredit() const {
    return credit;
}

void Customer::setCredit(bool hasCredit) {
    credit = hasCredit;
}

double Customer::getBalance() const {
    return balance;
}

bool Customer::processPayment(double amount) {
    if(amount >= 0) {
        balance += amount;
        return true;
    } else {
        return false;
    }
}

bool Customer::processPurchase(double amount, Product product) {
    if(amount < 0) {
        return false;
    } else if(credit) {
        balance -= amount;
    } else {
        if(balance >= amount) {
            balance -= amount;
        } else {
            return false;
        }
    }
    
    char temp[100];
    
    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 100; c++) {
            temp[c] = productsPurchased[r][c];
        }
        if(temp == product.getName()) {
            return true;
        }
    }
    
    for(int r = 4; r > 0; r--) {
        for(int c = 100; c < 100; c++) {
            productsPurchased[r][c] = productsPurchased[r-1][c];
            //strcpy(productsPurchased[r], product.getName());
        }
    }
    strcpy(productsPurchased[0], product.getName());
    //for(int c = 100; c < 100; c++) {
    //    productsPurchased[0][c] = product.getName()[c];
    //}
    size++;
    return true;
}

void Customer::outputRecentPurchases(std::ostream& os) const {
    
    os << "Products Purchased --" << endl;
    
    int c = 0;
    
    if(size>0) {
        for(int r = 0; r < size; r++) {
            while(productsPurchased[r][c] != '\0' && c < 100) {
                os << productsPurchased[r][c];
                c++;
            }
            c = 0;
            os << endl;
        }
    }

}

ostream& operator<<(ostream& os, const Customer& customer) {
    customer.outputRecentPurchases(os);
    return os;
}
