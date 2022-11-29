#ifndef FISTFULLODOLLARS_H
#define FISTFULLODOLLARS_H
#include"Player.h"
class FistfullODollars:public Player{
    int ff_index_move;
    char fMove;
    public:
    FistfullODollars();
    FistfullODollars(int f);
    void makeMove();
    char getMove();
    void resetIndex(int a);
    ~FistfullODollars();
   
};
#endif