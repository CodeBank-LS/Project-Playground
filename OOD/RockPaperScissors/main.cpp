#include"Tournament.h"
#include<iostream>
#include<stdlib.h>
#include<array>
using namespace std;
int main(){
    array<Player*, 8> competitors;

    competitors[0]=new Avalanche(1);//r
    competitors[1]=new Bureaucrat(2);//p
    competitors[2]=new Bureaucrat(3);//p
    competitors[3]=new Toolbox(4);//s
    competitors[4]=new Toolbox(5);//s
    competitors[5]=new Crescendo(6);//psr
    competitors[6]=new Crescendo(7);//psr
    competitors[7]=new FistfullODollars(8);//rpp
    Tournament t1;
    int flag_dupIDcheck=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
        if((competitors[i]->getID()==competitors[j]->getID())&&i!=j){
            flag_dupIDcheck=0;
        }else{
            flag_dupIDcheck=1;
        }
        }
    }


    if(flag_dupIDcheck==0){
       cout<<"duplicate id"<<endl;
    }else{
        if(t1.run(competitors)==competitors[0]){
            cout<<"Avalanche"<<endl;
        }else if(t1.run(competitors)==competitors[1]||t1.run(competitors)==competitors[2]){
            cout<<"Bureaucrat"<<endl;
        }else if(t1.run(competitors)==competitors[4]||t1.run(competitors)==competitors[5]){
            cout<<"Toolbox"<<endl;
        }else if(t1.run(competitors)==competitors[6]||t1.run(competitors)==competitors[7]){
            cout<<"Crescendo"<<endl;
        }else if(t1.run(competitors)==competitors[8]){
            cout<<"FistfullODollars"<<endl;
        }
    }
   

   return 0;
}