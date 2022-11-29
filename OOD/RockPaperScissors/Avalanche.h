#ifndef AVALANCHE_H
#define AVALANCHE_H
#include"Player.h"
class Avalanche:public Player{
    char avalancheMove;
    int ava_index;
    public:
    Avalanche();
    Avalanche(int a);
    char getMove();
    void resetIndex(int a);
    ~Avalanche();
};
#endif

