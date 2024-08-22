#include <iostream>
#include <cstring>
#include <sstream>
#include "Store.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

int Store::counter = 0; // defines and initializes

Store::Store() {
    setName("");
    numCustomers = 0;
    numProducts = 0;
}

Store::Store(const char name[]) {
    setName(name);
    numCustomers = 0;
    numProducts = 0;
}

const char* Store::getName() {
    return name;
}

void Store::setName(const char storeName[]) {
    if (strlen(storeName) > 0) {
        strcpy(this->name, storeName);
    }
    else {
        counter++;
        ostringstream oss;
        oss << "Store " << counter;
        strcpy(this->name, oss.str().c_str());
    }
}

bool Store::addProduct(int productID, const char productName[]) {
    if(numProducts == 100) {
        return false;
    }
    
    for(int i = 0; i < numProducts; i++) {
        if(products[i]->getID() == productID) {
            return false;
        }
    }
    
    products[numProducts] = new Product(productID, productName);
    numProducts++;
    
    return true;
}

Product* Store::getProduct(int productID) {
    for(int i = 0; i < numProducts; i++) {
        if(products[i]->getID() == productID) {
            return products[i];
        }
    }
    
    return nullptr;
}

bool Store::addCustomer(int customerID, const char customerName[], bool credit) {
    if(numCustomers == 100) {
        return false;
    }
    
    for(int i = 0; i < numCustomers; i++) {
        if(customers[i]->getID() == customerID) {
            return false;
        }
    }
    
    customers[numCustomers] = new Customer(customerID, customerName, credit);
    numCustomers++;
    
    return true;
}

Customer* Store::getCustomer(int customerID) {
    for(int i = 0; i < numCustomers; i++) {
        if(customers[i]->getID() == customerID) {
            return customers[i];
        }
    }
    
    return nullptr;
}


bool Store::takeShipment(int productID, int quantity, double cost) {
    if(quantity < 0 || cost < 0) {
        return false;
    }
    
    for(int i = 0; i < numProducts; i++) {
        if(products[i]->getID() == productID) {
            products[i]->addShipment(quantity, cost);
            return true;
        }
    }
    return false;
}

bool Store::sellProduct(int customerID, int productID, int quantity) {
    bool c, p;
    
    if(getCustomer(customerID)->getBalance() < getProduct(productID)->getPrice() || !(getCustomer(customerID)->getCredit())) {
        return false;
    }
    if(quantity < 0 || getProduct(productID)->getInventoryCount() < quantity) {
        return false;
    }
    
    c = getCustomer(customerID)->processPurchase((getProduct(productID)->getPrice())*quantity, *getProduct(productID));
    p = getProduct(productID)->reduceInventory(quantity);
    
    return true;
}

bool Store::takePayment(int customerID, double amount) {
    bool p = false;
    if(getCustomer(customerID)!=nullptr) {
        p = getCustomer(customerID)->processPayment(amount);
    }
    return p;
}

void Store::outputProducts(std::ostream& os) {
    for(int i = 0; i < numProducts; i++) {
        //os << products[i] << endl;
    }
}

void Store::outputCustomers(std::ostream& os) {
    for(int i = 0; i < numCustomers; i++) {
        //os << customers[i] << endl;
    }
}
