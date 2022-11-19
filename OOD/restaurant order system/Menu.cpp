#include"Menu.h"

Menu::Menu(){
    meals={{}};
}

void Menu::addMeal(Meal* ml){
    meals.push_back(ml);
}

void Menu::removeMeal(Meal* ml){
    for(int i=0;i<meals.size();i++){
        if(meals[i]==ml){
            meals.erase(meals.begin()+i);
        }
    }
}

void Menu::printMenu(){
    cout<<"Menu:"<<endl;
    for(int i=0;i<meals.size();i++){
        cout<<meals[i]->get_ID()<<"."<<meals[i]->get_Name()<<" "<<meals[i]->get_Price()<<endl;
    }
}

Menu::~Menu(){
    for(int i=0;i<meals.size();i++){
        delete meals[i];
    }
}