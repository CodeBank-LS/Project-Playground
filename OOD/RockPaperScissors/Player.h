#ifndef PLAYER_H
#define PLAYER_H

class Player{
 public:
 Player();
 Player(int a);
 void setID(int n);
 int getID();
 virtual void makeMove();
 virtual char getMove()=0;
 virtual void resetIndex(int a);
 ~Player();
 private:
    char pMove;
    int player_id;
    int player_index;

};
#endif