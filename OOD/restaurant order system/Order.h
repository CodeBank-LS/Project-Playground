//
// order number
//table number
//vector<menuIterm> dishes
//total price
//bool paid/not
//

#ifndef MENU_ORDER_H
#define MENU_ORDER_H
#include <string>
#include <vector>
#include<vector>
#include <map>
#include "Meal.h"
#include "Table.h"
#include "Customer.h"
using namespace std;
class Order{
private:
    int orderNumber;
    int tableNumber;
    string orderType;
    Customer customer;
    vector<Meal> dishes;
    double totalPrice;
    bool paid;
public:
    Order();
    void addDish(Meal meal){

    };
    void removeDish(Meal meal){

    };
    void set_orderNumber(int orderNumber);
    //void set_tableNumber(int tableNumber);
    void set_customer(Customer customer);
    virtual void get_totalPrice()=0;
   
    void printOrder();
    void set_paid(bool paid);
    
    ~Order();
};

#endif //MENU_ORDER_H
