#include"Menu.h"

Menu::Menu(string menutype){
    this->menuType=menutype;
}

void Menu::addMeal(Meal* ml){
    int answer;
    cout<<"Which menu do you want to add meal in?"<<endl;
    cout<<"1. Lunch Menu"<<"        "<<"2. Dinner Menu"<<endl;
    cin>>answer;
    if(answer==1){
        Menu1.push_back(ml);

    }else if(answer==2){
        Menu2.push_back(ml);
    }else{
        cout<<"Choose the menu to add or quit";
    }

}