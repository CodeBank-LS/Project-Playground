
//

#include "Customer.h"
Customer::Customer() {
    customerName = "";
    customerContact = "";
    orderNumber = 0;
}

Customer::Customer(string cName, string cContact){
    customerName = cName;
    customerContact = cContact;

    orderNumber = 0;
}

void Customer::set_customerName(string customerName) {
    this->customerName = customerName;
}

string Customer::get_customerName() {
    return customerName;
}

void Customer::set_customerContact(string customerContact) {
    this->customerContact = customerContact;
}

string Customer::get_customerContact() {
    return customerContact;
}


int Customer::checkOrder() {
    return orderNumber;
}

Customer::~Customer() {

}

