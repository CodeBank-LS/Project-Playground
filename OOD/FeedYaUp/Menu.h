
#ifndef MENU_H
#define MENU_H
#include"Meal.h"
#include <string>
#include <vector>
#include<iostream>
#include<vector>

using namespace std;
class Menu{
private:
    vector<Meal*> meals;
public:
    Menu();
    void addMeal(Meal* ml);
    void removeMeal(Meal* ml);
    void printMenu();
    ~Menu();

};

#endif //MENU_H