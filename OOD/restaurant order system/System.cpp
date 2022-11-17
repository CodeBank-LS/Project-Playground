#include"System.h"
System::System(){
   menu={{}};
}

void System::enterSys() {
    string name, phone;
    cout<<"Welcome to the FeedYaUp restaurant order system!"<<endl;
    cout<<"Please enter your name:"<<endl;
    cin>>name;
    cout<<"Please enter your phone number:"<<endl;
    cin>>phone;
    Customer(name, phone);
    cout<<"Welcome "<<name<<"!"<<endl;
    cout<<"Please choose the following options:"<<endl;
    cout<<"1. View menu"<<endl;
    cout<<"2. Place an order"<<endl;
    cout<<"3. View order history"<<endl;
    cout<<"4. Exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            showMenu();
            break;
        case 2:
            placeOrder();
            break;
        case 3:
            checkOrder();
            break;
        case 4:
            exitSys();
            break;
        default:
            cout<<"Invalid input, please enter again."<<endl;
            enterSys();
    }
}
void System::fillInfo(string name,string contact){
    Customer(name,contact);
    
}

void System::showMenu(){
    cout<<"Here is the menu:"<<endl;
    for(int i=0;i<menu.size();i++){
        cout<<i+1<<menu[i].get_Name()<<" "<<menu[i].get_Price()<<endl;
    }
    cout<<menu.size()<<" Return to previous menu"<<endl;
//    int choice;
//    cin>>choice;
//    switch(choice){
//        case 1:
//            menu.addFood("Chicken Burger", 10);
//            break;
//        case 2:
//            menu.addFood("Beef Burger", 12);
//            break;
//        case 3:
//            menu.addFood("Chicken Nuggets", 8);
//            break;
//        case 4:
//            menu.addFood("French Fries", 5);
//            break;
//        case 5:
//            menu.addFood("Coke", 3);
//            break;
//        case 6:
//            menu.addFood("Sprite", 3);
//            break;
//        case 7:
//            enterSys();
//            break;
//        default:
//            cout<<"Invalid input, please enter again."<<endl;
//            showMenu();
//    }
}