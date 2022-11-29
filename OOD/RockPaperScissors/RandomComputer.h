#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H
#include"Player.h"
class RandomComputer:public Player{
    char randomMove;
    int rand_index=0;
    public:
    RandomComputer();
    RandomComputer(int r);
    void makeMove();
    char getMove();
    void resetIndex(int a);
    ~RandomComputer();
};
#endif