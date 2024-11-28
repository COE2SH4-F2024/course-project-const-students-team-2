#include "Player.h"

Player::Player(){
    GameMechs gm = GameMechs();
    mainGameMechsRef = &gm;
    myDir = STOP;
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
}
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

    // more actions to be included
}

Player::Player(const Player &p){
    // Copy Assignment
    
    mainGameMechsRef = p.mainGameMechsRef;
    myDir = p.myDir;
    playerPos.setObjPos(p.playerPos);
}

Player& Player::operator= (const Player &p)
{
    // Copy Operator
	if (this != &p){
        
        this->mainGameMechsRef = p.mainGameMechsRef;
        this->myDir = p.myDir;
        this->playerPos.setObjPos(p.playerPos);
	}
	return *this;
}

Player::~Player()
{
    // delete any heap members here
    delete[] &playerPos;


}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic      
    char input = mainGameMechsRef->getInput();

    if (input >= 'a' && input <= 'z'){
        input -= 32;
    }

    if (input == 'W' && myDir != DOWN){
        myDir = UP;
    }
    else if (input == 'A' && myDir != RIGHT){
        myDir = LEFT;
    }
    else if (input == 'S' && myDir != UP){
        myDir = DOWN;
    }
    else if (input == 'D' && myDir != LEFT){
        myDir = RIGHT;
    }
    else if (input == ' '){
        mainGameMechsRef->setExitTrue();
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (myDir){
        case UP:
            if (playerPos.pos->y > 1){
                playerPos.pos->y --;
            }
            else{
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
            }
            break;
        case DOWN:
            if (playerPos.pos->y < mainGameMechsRef->getBoardSizeY()-2){
                playerPos.pos->y ++;
            }
            else{
                playerPos.pos->y = 1;
            }
            break;
        case LEFT:
            if (playerPos.pos->x > 1){
                playerPos.pos->x--;
            }
            else{
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
            }
            break;
        case RIGHT:
            if (playerPos.pos->x < mainGameMechsRef->getBoardSizeX()-2){
                playerPos.pos->x ++;
            }
            else{
                playerPos.pos->x = 1;
            }
            break;
        default:
            break;
    }
}

// More methods to be added