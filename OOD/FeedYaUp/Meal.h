

#ifndef MEAL_H
#define MEAL_H
#include <string>
using namespace std;
class Meal{
private:
    int ID;
    string Name;
    double Price;
public:
    Meal();
    Meal(int id,string name, double price);
    void set_ID(int id);
    void set_Name(string name);
    void set_Price(double price);
    int get_ID();
    string get_Name();
    double get_Price();
    ~Meal();
};

#endif //MEAL_H
