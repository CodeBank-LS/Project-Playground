//

#ifndef MENU_ORDER_H
#define MENU_ORDER_H
#include <string>
#include <vector>
#include<vector>
#include <map>
#include <iostream>
#include "Meal.h"
#include "Table.h"
#include "Customer.h"
using namespace std;
class Order{
private:
    int orderNumber;
    int numberPlp;
    int reservedTable;
    vector<Meal*> dishes;
    double totalPrice;
    bool paid;
public:
    Order();

    void chooseTable(Table* table);

    void set_numberPlp(int n);

    void addDish(Meal *meal);
    void removeDish(Meal *meal);
    double get_totalPrice();

    void payBill();

    void printOrder();


    
    ~Order();
};

#endif //MENU_ORDER_H
