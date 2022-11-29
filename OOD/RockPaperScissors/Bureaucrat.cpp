#include"Bureaucrat.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
Bureaucrat::Bureaucrat(){
    bureMove='P';
}

Bureaucrat::Bureaucrat(int b):Player(b){
    bureMove='P';
    //cout<<"Created Bureaucrat is Player "<<b<<endl;
}

char Bureaucrat::getMove(){
    return bureMove;
}

void Bureaucrat::resetIndex(int a){
    bu_index=a;
}
Bureaucrat::~Bureaucrat(){
    
}

