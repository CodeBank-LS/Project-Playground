

#ifndef MEAL_H
#define MEAL_H
#include <string>
using namespace std;
class Meal{
private:
    string Name;
    double Price;
public:
    Meal(string name, double price);
    void set_Name(string Name);
    void set_Price(double Price);
    string get_Name();
    double get_Price();
};
#endif //MEAL_H
