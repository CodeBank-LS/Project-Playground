#include"Avalanche.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
Avalanche::Avalanche(){
    avalancheMove='R';
    ava_index=0;
}

Avalanche::Avalanche(int a):Player(a){
    avalancheMove='R';
    //cout<<"Created Avalanceh is Player "<<a<<endl;
}

char Avalanche::getMove(){
    return avalancheMove;
}

void Avalanche::resetIndex(int a){
    ava_index=a;
}
Avalanche::~Avalanche(){

}
/*
int main(){
    Player *a=new Avalanche;
    cout<<a->makeMove()<<endl;
}
*/