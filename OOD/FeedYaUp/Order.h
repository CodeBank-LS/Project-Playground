//Class order include class meal
//order can add/remove meal from vector
//order should include table

#ifndef MENU_ORDER_H
#define MENU_ORDER_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Meal.h"
#include "Table.h"

using namespace std;
static int orderNumber = 100;
class Order{
private:
    int orderNumber;
    int numberPlp;
    int reservedTable;
    vector<Meal*> dishes;
    vector<Table*> tables;
    double totalPrice;
    bool paid;
public:
    Order();

    void bookTable(Table* table);
    void set_numberPlp(int n);

    int get_orderNumber();

    void addDish(Meal *meal);
    void removeDish(Meal *meal);
    double get_totalPrice();

    void payBill();

    void printOrder();

    ~Order();
};

#endif //MENU_ORDER_H
