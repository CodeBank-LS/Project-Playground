#include"PaperDoll.h"
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;



PaperDoll::PaperDoll(){
    pdMove='\0';
    pd_index_move=0;  
}
PaperDoll::PaperDoll(int p):Player(p){
    pdMove='\0';
    pd_index_move=0; 
    //cout<<"Created PaperDoll is Player "<<p<<endl;
}

void PaperDoll::makeMove(){
    char pd[3]={'P','S','S'};
    int pd_current_index=pd_index_move%3;
    pdMove=pd[pd_current_index];
    pd_index_move++;
}

char PaperDoll::getMove(){
    return pdMove;
}

void PaperDoll::resetIndex(int a){
    pd_index_move=a;
}

PaperDoll::~PaperDoll(){

}
