#include"Human.h"
#include<iostream>
#include<stdlib.h>

using namespace std;
Human::Human()
{
    hMove='\0';
    hdraft='\0';
}
Human::Human(int h):Player(h){
    hMove='\0';
    hdraft='\0';
    //cout<<"Player "<<h<<" is Human"<<endl;
}
void Human::makeMove()
{
    cout<<"Enter move:";
    cin>>hdraft;
    
    if(hdraft=='R'||hdraft=='P'||hdraft=='S'){
        hMove=hdraft;  
    }else{cout<<"invalid input"<<endl;}
}

char Human::getMove(){
    return hMove;
}

Human::~Human()
{

}