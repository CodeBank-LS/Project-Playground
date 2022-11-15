#include"System.h"
System::System(){
    cout<<"                            "<<endl;
    cout<<"                            "<<endl;
    cout<<"Welcome to MOF order systerm"<<endl;
    cout<<"                            "<<endl;
    cout<<"                            "<<endl;
    cout<<"                            "<<endl;
    cout<<"1. Reserve a Table"<<endl;
    cout<<"2. Start to Order"<<endl;
    cout<<"                            "<<endl;
    cout<<"3. Exit System"<<endl;
}
void System::fillInfo(string name,string contact){
    Customer* c;
    c->set_customerName(name);
    c->set_customerContact(contact);
    
}

void System::showMenu(){
    
}