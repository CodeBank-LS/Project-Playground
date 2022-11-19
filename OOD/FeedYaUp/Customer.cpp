
//

#include "Customer.h"
Customer::Customer() {
    customerName = "";
    customerContact = "";
    orders={};
}

Customer::Customer(string cName, string cContact){
    customerName = cName;
    customerContact = cContact;
    orderNumber = 0;
    orders={{}};
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

void Customer::add_order(Order* order) {
    orders.push_back(order);
}

void Customer::myOrders() {
    for(int i=0;i<orders.size();i++){
        cout<<orders[i]->get_orderNumber()<<endl;
    }
}

Customer::~Customer() {
    for(int i=0;i<orders.size();i++){
        delete orders[i];
    }
    orders.clear();
}

