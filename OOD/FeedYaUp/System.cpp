#include"System.h"
System::System(){

   tables={};
}



void System::addTable(Table* table) {
    if(table->get_available()==true){
        tables.push_back(table);
    }

}

void System::addMeal(Menu* menu, Meal* meal) {
    menu->addMeal(meal);
}

void System::removeMeal(Menu* menu, Meal* meal) {
    menu->removeMeal(meal);
}

void System::showMenu(Menu* m) {
    m->printMenu();
}

void System::showTables() {
    if(tables.size()==0){
        cout<<"Sorry, there are no tables available"<<endl;
    }else{
        for(int i=0;i<tables.size();i++){
            cout<<"Table No."<<tables[i]->get_tableID()<<" is available"<<endl;
        }
    }

}

Order* System::placeOrder() {
    Order* order = new Order();
    return order;
}

System::~System() {
    for(int i=0;i<tables.size();i++){
        delete tables[i];
    }
    tables.clear();
}

