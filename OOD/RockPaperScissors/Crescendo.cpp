#include"Crescendo.h"
#include<stdlib.h>
#include<iostream>
using namespace std;



Crescendo::Crescendo(){
    cresMove='\0';
    index_move=0;
   
}
Crescendo::Crescendo(int c):Player(c){
    cresMove='\0';
    index_move=0;
    //cout<<"Created Crescendo is Player "<<c<<endl;
}

void Crescendo::makeMove(){
    char cres[3]={'P','S','R'};
    int current_index=index_move%3;
    cresMove=cres[current_index];
    index_move++; 
}

char Crescendo::getMove(){
    return cresMove;
}

void Crescendo::resetIndex(int a){
    index_move=a;
}

Crescendo::~Crescendo(){

}
 /*
int main(){
    Player *c=new Crescendo;
    cout<<c->makeMove()<<endl;
    cout<<c->makeMove()<<endl;
    cout<<c->makeMove()<<endl;
    cout<<c->makeMove()<<endl;
    cout<<c->makeMove()<<endl;
    cout<<c->makeMove()<<endl;
    cout<<c->makeMove()<<endl;
  
}
*/