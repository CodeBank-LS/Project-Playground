#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include"Player.h"
class Bureaucrat:public Player{
    char bureMove;
    int bu_index;
    public:
    Bureaucrat();
    Bureaucrat(int b);
    char getMove();
    void resetIndex(int a);
    ~Bureaucrat();
};
#endif