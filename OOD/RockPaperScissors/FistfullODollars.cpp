#include"FistfullODollars.h"
#include<stdlib.h>
#include<iostream>

using namespace std;



FistfullODollars::FistfullODollars(){
    fMove='\0';
    ff_index_move=0;
    
}
FistfullODollars::FistfullODollars(int f):Player(f){
    fMove='\0';
    ff_index_move=0;
   // cout<<"Created FistfullODollars is Player "<<f<<endl;
}

void FistfullODollars::makeMove(){
    char ff[3]={'R','P','P'};
    int ff_current_index=ff_index_move%3;
    fMove=ff[ff_current_index];
    ff_index_move++;
}

char FistfullODollars::getMove(){
    return fMove;
}

void FistfullODollars::resetIndex(int a){
    ff_index_move=a;
}

FistfullODollars::~FistfullODollars(){
    
}


