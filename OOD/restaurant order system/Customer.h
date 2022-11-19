//
// customer name
//customer contact
//table reserved
//order number
//

#ifndef MENU_CUSTOMER_H
#define MENU_CUSTOMER_H
#include <string>
#include <vector>
#include<vector>
#include <map>
#include "Meal.h"
#include "Table.h"
#include "Order.h"
using namespace std;
class Customer{
private:
    string customerName;
    string customerContact;
    int orderNumber;
public:
    Customer();
    Customer(string cName, string cContact);
    void set_customerName(string customerName);
    string get_customerName();
    void set_customerContact(string customerContact);
    string get_customerContact();
    int checkOrder();
    ~Customer();





};
#endif //MENU_CUSTOMER_H
