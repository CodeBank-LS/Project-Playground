#ifndef HUMAN_H
#define HUMAN_H
#include"Player.h"
class Human: public Player{
    char hMove;
    char hdraft;
    public:
    Human();
    Human(int h);
    void makeMove();
    char getMove();
    ~Human();
   
    
};
#endif