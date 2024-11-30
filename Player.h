#ifndef PLAYER_H
#define PLAYER_H



#include "GameMechs.h"
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
        Player(GameMechs* thisGMRef);
        ~Player();
        Player(const Player &p);
        Player& operator= (const Player &p);

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3.       
        
        void movePlayer();

        // More methods to be added here

    private:
        //objPos playerPos; // Upgrade this in iteration 3.  
        void updatePlayerDir();     
        enum Dir myDir = STOP;

        objPosArrayList* playerPosList;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif