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
    int tableReserved;
    int orderNumber;
public:
    Customer();
    void set_customerName(string customerName);
    void set_customerContact(string customerContact);
    void chooseTable(Table* table);
    void set_TableReserved();





};
#endif //MENU_CUSTOMER_H
