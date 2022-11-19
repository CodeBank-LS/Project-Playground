//keep having errors like use of undeclared/unknown type
//problem is solved to declare the class in right order: table<order<customer
//something can be refined in the future: admin class to manage the system
//a customer should be able to book more than 1 table and multiple orders
//the add meal and remove meal can be done in one enter like A1(add meal 1) or R2(remove meal 2)
//some input restrictions can be added to avoid bullshit input
#include"Customer.h"
#include"Meal.h"
#include"Order.h"
#include"Table.h"
#include"Menu.h"
#include"System.h"
#include <iostream>
using namespace std;



int main(){
    //中西混搭 选择困难症最爱点餐方式
    Meal* m1 = new Meal(1,"Chicken Rice 神魂颠倒鸡肉炒饭", 12.9);
    Meal* m2 = new Meal(2,"Beef Noodle 欲罢不能牛肉面", 14);
    Meal* m3 = new Meal(3,"Fried Fish 赛神仙炸鱼", 15);
    Meal* m4 = new Meal(4,"Fried Fries 管他肥不肥我就爱吃薯条", 7.9);
    Meal* m5 = new Meal(5,"Salad 仙女沙拉", 9.9);
    Meal* m6 = new Meal(6,"Sandwich 社畜加班三明治", 10);
    Meal* m7 = new Meal(7,"Soft Drink 快乐肥宅水", 3);

    Menu menu;//menu include 7 choices for customer to order
    menu.addMeal(m1);
    menu.addMeal(m2);
    menu.addMeal(m3);
    menu.addMeal(m4);
    menu.addMeal(m5);
    menu.addMeal(m6);
    menu.addMeal(m7);

    //小本经营，饭店就5张桌子
    Table* t1 = new Table(1);
    Table* t2 = new Table(2);
    Table* t3 = new Table(3);
    Table* t4 = new Table(4);
    Table* t5 = new Table(5);

    System system;
    system.addTable(t1);
    system.addTable(t2);
    system.addTable(t3);
    system.addTable(t4);
    system.addTable(t5);


    cout<<"Welcome to the FeedYaUp restaurant order system!"<<endl;
    cout<<"Please enter your name: "<<endl;
    string name;
    cin>>name;
    cout<<"Please enter your phone number: "<<endl;
    string phone;
    cin>>phone;
    Customer* customer = new Customer(name, phone);

    cout<<"Welcome "<<name<<"!"<<endl;
    cout<<"Are you ready to order now? (Y/N)"<<endl;
    char choice1;
    cin>>choice1;
    //构建一个order
    Order* yourOrder;
    yourOrder = system.placeOrder();
    customer->add_order(yourOrder);
    //订桌
    if(choice1=='Y'||choice1=='y'){
        cout<<"please choose a table first:"<<endl;
        system.showTables();
        cout<<"Please enter the table number:"<<endl;
        int tableID;
        cin>>tableID;
        if(tableID==1){
            t1->set_booked();//change the table status to booked
            yourOrder->bookTable(t1);//add the table to the order
        }
        else if(tableID==2){
            t2->set_booked();
            yourOrder->bookTable(t2);
        }
        else if(tableID==3){
            t3->set_booked();
            yourOrder->bookTable(t3);
        }
        else if(tableID==4){
            t4->set_booked();
            yourOrder->bookTable(t4);
        }
        else if(tableID==5){
            t5->set_booked();
            yourOrder->bookTable(t5);
        }
        else{
            cout<<"Sorry, please enter available table number."<<endl;
        }

        cout<<"Table "<<tableID<<" is booked!"<<endl;

        cout<<"How many people are there?"<<endl;
        int people;
        cin>>people;
        yourOrder->set_numberPlp(people);

        //展示菜单
        cout<<"The menu is as follows:"<<endl;
        system.showMenu(&menu);
        cout<<"Continue to order? (Y/N)"<<endl;
        char choice2;
        cin>>choice2;

        while(choice2!='N'||choice2!='n'){
            cout<<"Please enter the meal number you want to order:"<<endl;
            int mealID;
            cin>>mealID;

            if(mealID==1){
                yourOrder->addDish(m1);
            }
            else if(mealID==2){
                yourOrder->addDish(m2);
            }
            else if(mealID==3){
                yourOrder->addDish(m3);
            }
            else if(mealID==4){
                yourOrder->addDish(m4);
            }
            else if(mealID==5){
                yourOrder->addDish(m5);
            }
            else if(mealID==6){
                yourOrder->addDish(m6);
            }
            else if(mealID==7){
                yourOrder->addDish(m7);
            }else{
                cout<<"Please enter the correct meal number!"<<endl;
            }
            cout<<"Continue to order? (Y/N)"<<endl;
            cin>>choice2;
            if(choice2=='N'||choice2=='n'){
                break;
            }

        }
        cout<<"Your order is as follows:"<<endl;
        yourOrder->printOrder();
        cout<<"Do you need to delete any meal? (Y/N)"<<endl;
        char choice4;
        cin>>choice4;
        if(choice4=='Y'||choice4=='y'){
            cout<<"Please enter the meal number you want to delete:"<<endl;
            int mealID;
            cin>>mealID;
            if(mealID==1){
                yourOrder->removeDish(m1);
            }
            else if(mealID==2){
                yourOrder->removeDish(m2);
            }
            else if(mealID==3){
                yourOrder->removeDish(m3);
            }
            else if(mealID==4){
                yourOrder->removeDish(m4);
            }
            else if(mealID==5){
                yourOrder->removeDish(m5);
            }
            else if(mealID==6){
                yourOrder->removeDish(m6);
            }
            else if(mealID==7){
                yourOrder->removeDish(m7);
            }else{
                cout<<"Please enter the correct meal number!"<<endl;
            }
            cout<<"Your order is as follows:"<<endl;
            yourOrder->printOrder();
        }
        cout<<"Please pay the bill (Y/N):"<<endl;
        char choice3;
        cin>>choice3;
        if(choice3=='Y'||choice3=='y'){
            yourOrder->payBill();
            cout<<"Thank you for your order!"<<endl;
            cout<<"客官请慢用！"<<endl;
        }else {
            cout << "There is an ATM out the right corner of restaurant." << endl;
            cout << "小本生意，概不赊账" << endl;
        }


        }else{
            cout<<"Thank you for visiting FeedYaUp!"<<endl;
        }


    return 0;
    }

