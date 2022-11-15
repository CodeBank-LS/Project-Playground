
#ifndef MENU_H
#define MENU_H
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include"Meal.h"
using namespace std;
class Menu{
private:
    string menuType;
    vector<Meal*> LunchMenu;
    vector<Meal*> DineMenu;
public:
    Menu(string menutype);
    void addMeal(Meal* ml);
    void removeMeal(Meal* ml);
    void printMenu(vector<Meal*> menu);
    ~Menu()

}

#endif //MENU_H