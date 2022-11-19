//
//

#ifndef MENU_TABLE_H
#define MENU_TABLE_H
#include <string>
#include <vector>
#include<vector>
#include <map>
#include "Meal.h"
#include "Customer.h"
#include "Order.h"
using namespace std;
class Table{
private:
    int tableID;
    int numOfPlp;
    bool available;
    int table_orderNumber;
public:
    Table();
    Table(int table_id);
    int get_tableID();
    void setPeople(int n);
    bool get_available();
    bool set_booked();
    bool clear_table();
    ~Table();
};



#endif //MENU_TABLE_H
