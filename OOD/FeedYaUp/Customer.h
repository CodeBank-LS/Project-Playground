//
// prompt to enter name and contact to construct a customer
// class customer include class order
//

#ifndef MENU_CUSTOMER_H
#define MENU_CUSTOMER_H
#include <string>
#include <vector>
#include <map>
#include "Meal.h"
#include "Table.h"
#include "Order.h"
using namespace std;
class Customer{
private:
    string customerName;
    string customerContact;

    vector<Order*> orders;
public:
    Customer();
    Customer(string cName, string cContact);
    void set_customerName(string customerName);
    string get_customerName();
    void set_customerContact(string customerContact);
    string get_customerContact();
    void add_order(Order* order);
    void myOrders();
    ~Customer();





};
#endif //MENU_CUSTOMER_H
