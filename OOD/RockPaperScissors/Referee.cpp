#include"Referee.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
Referee::Referee(){
    
    record1=0;
    record2=0;
}
int Referee::refPlay(Player *a,Player *b){
    char aMove='\0';
    char bMove='\0';
    int flag=1;
    if(a!=b){
      aMove = a->getMove();
      bMove = b->getMove();
     //using flag to determine play winner
    if(aMove=='R'&& bMove=='S'){
      //  cout<<a->getID()<<" won this play"<<endl;
        flag=1;
    }else if(aMove=='P'&& bMove=='R'){
      //  cout<<a->getID()<<" won this play"<<endl;
        flag=1;
    }else if(aMove=='S'&& bMove=='P'){
      //  cout<<a->getID()<<" won this play"<<endl;
        flag=1;
    }else if(bMove=='P'&& aMove=='R'){
      //  cout<<b->getID()<<" won this play"<<endl;
        flag=0;
    }else if(bMove=='R'&& aMove=='S'){
      //  cout<<b->getID()<<" won this play"<<endl;
        flag=0;
    }else if(bMove=='S'&& aMove=='P'){
       // cout<<b->getID()<<" won this play"<<endl;
        flag=0;
    }else if(aMove==bMove){
        if(a->getID()<=b->getID()){
      //      cout<<a->getID()<<" won this play"<<endl;
            flag=1;
        }else{
       //     cout<<b->getID()<<" won this play"<<endl;
            flag=0;
            }
    }
    }else{}
    return flag;

}
 
/*
Player* Referee::refRound(Player *a,Player *b){
  
   int aScore=0;
   int bScore=0;
   int cnt=0;
   while(cnt<=5){
       if(refPlay(a, b)==1){
           aScore++;
       }else if(refPlay(a,b)==0){
           bScore++;
       }
      cnt++;
   }

   if(cnt==5){
     a->resetIndex(0);
     b->resetIndex(0);
     aScore=0;
     bScore=0;
   }

   if(aScore>=bScore){
       return a;
      
   }else{
       return b;
   } 
}
*/

Referee::~Referee(){

}

