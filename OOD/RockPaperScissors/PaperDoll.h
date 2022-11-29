#ifndef PAPERDOLL_H
#define PAPERDOLL_H
#include"Player.h"
class PaperDoll:public Player{
    char pdMove;
    int pd_index_move;
    public:
    PaperDoll();
    PaperDoll(int p);
    void makeMove();
    char getMove();
    void resetIndex(int a);
    ~PaperDoll();
    
};
#endif
