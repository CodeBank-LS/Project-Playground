#ifndef CRESCENDO_H
#define CRESCENDO_H
#include"Player.h"
class Crescendo:public Player{
    char cresMove;
    int index_move;
    public:
    Crescendo();
    Crescendo(int c);
    void makeMove();
    char getMove();
    void resetIndex(int a);
    ~Crescendo();
    
    
    
};
#endif