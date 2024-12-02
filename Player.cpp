#include "Player.h"

Player::Player(){
    GameMechs gm = GameMechs();
    mainGameMechsRef = &gm;
    myDir = STOP;

    Food food = Food();
    mainFood = &food;
    

    playerPosList = new objPosArrayList();
    objPos headPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');

    playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos);
    
    
    
}
Player::Player(GameMechs* thisGMRef, Food* thisFood)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    mainFood = thisFood;
    playerPosList = new objPosArrayList();

    objPos headPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');
    playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos);

    // more actions to be included
    
}

Player::Player(const Player &p){
    // Copy Assignment
    
    mainGameMechsRef = p.mainGameMechsRef;
    myDir = p.myDir;
    mainFood = p.mainFood;
    playerPosList = new objPosArrayList();
    for (int i = 0; i<p.playerPosList->getSize(); i++){
        playerPosList->insertTail(p.getPlayerPos()->getElement(i));
    }

}

Player& Player::operator= (const Player &p)
{
    // Copy Operator
	if (this != &p){
        
        this->mainGameMechsRef = p.mainGameMechsRef;
        this->myDir = p.myDir;
        this->mainFood = p.mainFood;
        delete playerPosList;
        this->playerPosList = new objPosArrayList();
        this->playerPosList = p.playerPosList;
        for (int i = 0; i<p.playerPosList->getSize(); i++){
            playerPosList->insertTail(p.getPlayerPos()->getElement(i));
        }
	}
	return *this;
}

Player::~Player()
{
    // delete any heap members here

    delete playerPosList;

}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic      
    char input = mainGameMechsRef->getInput();

    if (input >= 'a' && input <= 'z'){
        input -= 32; // if W A S D are lowercase, capitalize them
    }

    switch (input){

        case 'W':
            if (myDir != DOWN){
                myDir = UP;
            }
            break;

         case 'A':
            if (myDir != RIGHT){
                myDir = LEFT;
            }
            break;

         case 'S':
            if (myDir != UP){
                myDir = DOWN;
            }
            break;

         case 'D':
            if (myDir != LEFT){
                myDir = RIGHT;
            }
            break;

        default:
            break;

    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    // I3: create a temp objPos to calculate the new head psoition
        // probably should get the head element of the player position list as a good starting point

    updatePlayerDir();

    nextHead = objPos(playerPosList->getHeadElement());
    int headX = nextHead.pos->x;
    int headY = nextHead.pos->y;
    
   
    // int foodX = food.getFoodpos().pos->x;
    // int foodY = food.getFoodpos().pos->y;

    

    switch (myDir){
        case UP:

            if (headY > 1)
            {
                nextHead.setObjPos(headX, headY-1, '@');
            }
            else
            {
                nextHead.setObjPos(headX, mainGameMechsRef->getBoardSizeY()-2, '@');
            }
            break;
        case DOWN:
            if (headY < mainGameMechsRef->getBoardSizeY()-2){
                nextHead.setObjPos(headX, headY+1, '@');
            }
            else{
                nextHead.setObjPos(headX, 1, '@');
            }
            break;

         case LEFT:
             if (headX > 1){
                nextHead.setObjPos(headX-1, headY, '@');
            }
            else{
                nextHead.setObjPos(mainGameMechsRef->getBoardSizeX()-2, headY, '@');
            }
             break;

         case RIGHT:
             if (headX < mainGameMechsRef->getBoardSizeX()-2){
                nextHead.setObjPos(headX+1, headY, '@');
            }
            else{
                nextHead.setObjPos(1, headY, '@');
            }
             break;

         default:
             break;
    }


    // Game over condition

    if (myDir != STOP){ // Won't check game over until snake starts moving
        
        for (int i = 0; i<playerPosList->getSize()-1; i++){ 
            // Doesn't need to check the last position because the last position will always disappear
                // (If the snake is eating food the last snake position is not removed, but the snake can't eat food and collide
                // with itself on the same space because food doesn't generate on any portion occupied by the snake)

            if (playerPosList->getElement(i).isPosEqual(&nextHead)){
                mainGameMechsRef->setLoseFlag();
            }
        }
    }

    increasePlayerLength();

    // Checking if the snake's head collided with any food

    bool ateFood = false;

    for (int i = 0; i<5; i++){
         if (mainFood->getFoodpos()->getElement(i).isPosEqual(&nextHead)){
            ateFood = true;
            mainGameMechsRef->incrementScore();
         }
    }
    

    

    if (ateFood){
        mainFood->generateFood(playerPosList);
    }
    else{
        playerPosList->removeTail(); // only removing the last position if no food was
    }
   
    // use isPosEqual() from objPos class
    // If overlapped, food consumed, don't remove snake tail
    // Increase score
}

// More methods to be added
bool Player::checkFoodConsumption()
{
    
}

void Player::increasePlayerLength()
    {
playerPosList->insertHead(nextHead); // Inserting new head
}