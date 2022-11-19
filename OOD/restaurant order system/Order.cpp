
#include "Order.h"

Order::Order() {
    reservedTable = 0;
    int numberPlp=0;
    orderNumber = 1;
    totalPrice = 0;
    paid = false;
    dishes={{}};
}

void Order::chooseTable(Table *table) {
    reservedTable = table->get_tableID();

}

void Order::set_numberPlp(int n) {
    numberPlp = n;
}
void Order::addDish (Meal *meal) {
    dishes.push_back(meal);
    totalPrice += meal->get_Price();
}

void Order::removeDish(Meal *meal) {
    for (int i = 0; i < dishes.size(); i++) {
        if (dishes[i] == meal) {
            dishes.erase(dishes.begin() + i);

        }
    }
}

double Order::get_totalPrice() {
    for(int i=0;i<dishes.size();i++){
        totalPrice+=dishes[i]->get_Price();
    }
    return totalPrice;
}

void Order::payBill() {
    paid = true;
}

void Order::printOrder() {
    cout<< "Table Number: "<<reservedTable<<endl;
    cout<< "Number of People: "<<numberPlp<<endl;
    cout << "Order Number: " << orderNumber << endl;
    cout << "Dishes: " << endl;
    for (int i = 0; i < dishes.size(); i++) {
        cout << dishes[i]->get_ID() << "." << dishes[i]->get_Name() << " " << dishes[i]->get_Price() << endl;
    }
    cout << "Total Price: " << totalPrice << endl;
    cout << "Paid: " << paid << endl;
}

