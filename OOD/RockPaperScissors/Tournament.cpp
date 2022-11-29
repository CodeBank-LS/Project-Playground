#include"Tournament.h"
#include<iostream>
#include<stdlib.h>
#include<array>
using namespace std;
Tournament::Tournament(){ 

}
Player* refRound(Player *a, Player *b){
    Referee ref;
    int aScore=0;
    int bScore=0;
    int cnt=0;
    while(cnt<=5){
       if(ref.refPlay(a, b)==1){
           aScore++;
       }else if(ref.refPlay(a,b)==0){
           bScore++;
       }
      cnt++;
     }
    //reset memory
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

Player* Tournament::run(array<Player *, 8>  competitors){
    
    
    Player* r1=refRound(competitors[0],competitors[1]);
    Player* r2=refRound(competitors[2],competitors[3]);
    Player* r3=refRound(competitors[4],competitors[5]);
    Player* r4=refRound(competitors[6],competitors[7]);
    Player* r5=refRound(r1,r2);
    Player* r6=refRound(r3,r4);
    Player* r7=refRound(r5,r6);
    return r7;
    
}

Tournament::~Tournament() {

}