#include "Table.h"
Table::Table(){
    tableID = 0;
    numOfPlp = 0;
    available = true;
    tableOrder = nullptr;
}
Table::Table(int table_id) {
    this->tableID=table_id;
    this->available=true;
}

void Table::setPeople(int n) {
    this->numOfPlp=n;
}

int Table::get_tableID() {
    return tableID;
}

bool Table::get_available() {
    return available;
}


bool Table::set_booked() {
    if(available){
        available=false;
        return true;
    }
    else{
        return false;
    }
}

bool Table::clear_table() {
    if(!available){
        available=true;
        return true;
    }
    else{
        return false;
    }
}

Table::~Table() {
}