#include"Toolbox.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
Toolbox::Toolbox(){
    tbMove='S';
    tb_index=0;
}

Toolbox::Toolbox(int t):Player(t){
    tbMove='S';
    //cout<<"Created Toolbox is Player "<<t<<endl;
}

void Toolbox::makeMove(){
    
}

char Toolbox::getMove(){
    return tbMove;
}

void Toolbox::resetIndex(int a){
    tb_index=a;
}

Toolbox::~Toolbox(){

}


 