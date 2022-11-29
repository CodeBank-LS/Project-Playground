#ifndef TOOLBOX_H
#define TOOLBOX_H
#include"Player.h"
class Toolbox:public Player{
    char tbMove;
    int tb_index;
    public:
    Toolbox();
    Toolbox(int t);
    void makeMove();
    char getMove();
    void resetIndex(int a);
    ~Toolbox();
};
#endif