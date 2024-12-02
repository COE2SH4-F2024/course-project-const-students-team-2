#ifndef PLAYER_H
#define PLAYER_H



#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        Player();
        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();
        Player(const Player &p);
        Player& operator= (const Player &p);

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3.       
        
        void movePlayer();

        // More methods to be added here
        bool checkFoodConsumption();
        void increasePlayerLength();

    private:
        //objPos playerPos; // Upgrade this in iteration 3.  
        void updatePlayerDir();     
        enum Dir myDir = STOP;
        objPos nextHead;

        objPosArrayList* playerPosList;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainFood;
        // Food food; 
};

#endif