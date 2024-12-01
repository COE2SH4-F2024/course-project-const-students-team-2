#include "Player.h"

Player::Player(){
    GameMechs gm = GameMechs();
    mainGameMechsRef = &gm;
    myDir = STOP;

    Food food = Food();
    foodpos = &food;
    //food = Food();

    playerPosList = new objPosArrayList();
    objPos headPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');

    playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos);
    // playerPosList->insertHead(headPos);
    
    
    
}
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    foodpos = foodpos;
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
    foodpos = p.foodpos;
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
        this->foodpos = p.foodpos;
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

    objPos temp = objPos(playerPosList->getHeadElement());
    int headX = temp.pos->x;
    int headY = temp.pos->y;
    
   
    // int foodX = food.getFoodpos().pos->x;
    // int foodY = food.getFoodpos().pos->y;

    switch (myDir){
        case UP:

            if (headY > 1)
            {
                temp.setObjPos(headX, headY-1, '@');
            }
            else
            {
                temp.setObjPos(headX, mainGameMechsRef->getBoardSizeY()-2, '@');
            }
            break;
        case DOWN:
            if (headY < mainGameMechsRef->getBoardSizeY()-2){
                temp.setObjPos(headX, headY+1, '@');
            }
            else{
                temp.setObjPos(headX, 1, '@');
            }
            break;

         case LEFT:
             if (headX > 1){
                temp.setObjPos(headX-1, headY, '@');
            }
            else{
                temp.setObjPos(mainGameMechsRef->getBoardSizeX()-2, headY, '@');
            }
             break;

         case RIGHT:
             if (headX < mainGameMechsRef->getBoardSizeX()-2){
                temp.setObjPos(headX+1, headY, '@');
            }
            else{
                temp.setObjPos(1, headY, '@');
            }
             break;

         default:
             break;
    }


    // playerPosList->insertHead(temp);
    // playerPosList->removeTail();

    // Insert temp objPos to head of the list
    // Iter 3 (later) check if new temp object position overlaps food position (get it from gameMechs)

    objPos food = foodpos->getFoodpos();
    
    if (headX == food.pos->x && headY == food.pos->y)
    {
        playerPosList->insertHead(temp);
        //food.generateFood(*playerPosList);
        mainGameMechsRef->incrementScore();
    }
    else
    {
        playerPosList->insertHead(temp);
        playerPosList->removeTail();
    }
    // use isPosEqual() from objPos class
    // If overlapped, food consumed, don't remove snake tail
    // Increase score
}

// More methods to be added
bool Player::checkFoodconsumption()
{
    // objPos foodpos = food.getFoodpos();
    // objPos temp = objPos(playerPosList->getHeadElement());
    
    // if (temp.isPosEqual(&foodpos) == true)
    // {
    //     playerPosList->insertHead(temp);
    //     food.generateFood(temp.getObjPos());
    //     return true;
    // }
    // else
    // {
    //     playerPosList->insertHead(temp);
    //     playerPosList->removeTail();
        
    // }
}

void Player::increasePlayerLength()
{

}