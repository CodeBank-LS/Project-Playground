#include "Meal.h"
Meal::Meal() {
    ID = 0;
    Name = "";
    Price = 0;
}
Meal::Meal(int id,string name, double price) {
    ID=id;
    Name = name;
    Price = price;
}
void Meal::set_ID(int id) {
    ID=id;
}
void Meal::set_Name(string name) {
    Name=name;
}
void Meal::set_Price(double price) {
    Price=price;
}

int Meal::get_ID() {
    return ID;
}

string Meal::get_Name() {
    return Name;
}


double Meal::get_Price() {
    return Price;
}

Meal::~Meal() {

}

