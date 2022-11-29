#ifndef REFEREE_H
#define REFEREE_H
#include"Avalanche.h"
#include"Bureaucrat.h"
#include"Crescendo.h"
#include"FistfullODollars.h"
#include"Human.h"
#include"PaperDoll.h"
#include"RandomComputer.h"
#include"Toolbox.h"

class Referee{
    public:
    Referee();
    int refPlay(Player *a,Player *b);
   // Player* refRound(Player *a,Player *b);
   // char giveResult();
    
    int record1;
    int record2;
    ~Referee();
};
#endif