#ifndef PLAYER_H
#define PLAYER_H



#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        Player();
        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();
        Player(const Player &p);
        Player& operator= (const Player &p);

        objPosArrayList* getPlayerPos() const;     
        
        void movePlayer();

        bool checkFoodConsumption();
        void increasePlayerLength();

    private:
        void updatePlayerDir();     
        enum Dir myDir = STOP;
        objPos nextHead;

        objPosArrayList* playerPosList;

        GameMechs* mainGameMechsRef;
        Food* mainFood;
};

#endif