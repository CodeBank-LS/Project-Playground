#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include<vector>
#include<stdio.h>
#include"Customer.h"
#include"Meal.h"
#include"Order.h"
#include"Table.h"
#include"Menu.h"
using namespace std;
class System{
private:
    vector<Table*> tables;
public:
    System();

    void addMeal(Menu* menu, Meal* meal);
    void addTable(Table* table);

    void removeMeal(Menu* menu, Meal* meal);
    void showMenu(Menu* m);
    void showTables();

    Order* placeOrder();
    ~System();

};


#endif //SYSTEM_H