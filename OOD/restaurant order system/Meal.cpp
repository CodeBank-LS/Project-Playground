#include "Meal.h"

Meal::Meal(string name, double price) {
    this->Name = name;
    this->Price = price;
}
void Meal::set_Name(string name) {
    this->Name = name;
}

string Meal::get_Name() {
    return Name;
}

void Meal::set_Price(double price) {
    this->Price = price;
}

double Meal::get_Price() {
    return Price;
}

