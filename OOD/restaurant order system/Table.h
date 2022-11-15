//
// table number
//bool available/not
//start time
//finish time
//time session over 2h will set table table to available
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
    int tableNumber;
    int numOfPlp;
    bool TableAvaliable;
    vector<Order> tableOrder;
public:
    Table();
    Table(int order_number);
    void set_numOfplp(int n);
    void set_tableOrdeer();
    Order* get_tableOrder();
    void checkTablestatus();

   
    ~Table();
};



#endif //MENU_TABLE_H
