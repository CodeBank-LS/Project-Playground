//Table number and table status
//

#ifndef MENU_TABLE_H
#define MENU_TABLE_H
#include <string>
#include <vector>
#include<vector>
#include <map>

using namespace std;
class Table{
private:
    int tableID;
    int numOfPlp;
    bool available;

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
