#include"RandomComputer.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


RandomComputer::RandomComputer(){
    randomMove='\0';
    rand_index=0;
  
}
RandomComputer::RandomComputer(int r):Player(r){
    randomMove='\0';
   // cout<<"Created RandomComputer is Player "<<r<<endl;
}

void RandomComputer::makeMove(){
    srand((unsigned)time(NULL));
    int index=rand()%3;
    char moves[3]={'R','P','S'};
    randomMove=moves[index]; 
}

char RandomComputer::getMove(){
    return randomMove;
}

void RandomComputer::resetIndex(int a){
    rand_index=a;
}

RandomComputer::~RandomComputer(){

}
