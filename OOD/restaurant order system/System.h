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
    vector<Meal> menu;
public:
    System();
    void enterSys();
    void fillInfo(string name,string contact);
    void removeMeal();
    void showMenu(Menu* m);
    void placeOrder();
    void bookTable();
    void payBill();

};


#endif //SYSTEM_H