#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000



Player* player;
GameMechs* gameMechs;
Food* food; 




void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(gameMechs->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    

    gameMechs = new GameMechs(); //creating gamemechs on the heap
    player = new Player(gameMechs);
    food = new Food();
    food->generateFood(player->getPlayerPos());
    
}

void GetInput(void)
{
    
    gameMechs->getInput();
    //DEBUGGING CHANGING RANDOM ON THE FLY WITH DEBUG-KEY 
    if (gameMechs->getInput() == 'n')
    {
        // !!!!
        // Cycle through all snake segments and make sure food isn't there
        food->generateFood(player->getPlayerPos());
        gameMechs->clearInput();
        
    }
}

void RunLogic(void)
{
    
    if (gameMechs->getInput()==' ')
    {
        gameMechs->setExitTrue();
        gameMechs->clearInput();
    }
    else
    {
        player->movePlayer();
        gameMechs->incrementScore(); //DEBUGGING REMOVE LATER
        
        
        
    }
    
    

}

void DrawScreen(void)
{
    int row,column = 0;

    objPosArrayList * playerPos = player->getPlayerPos();
    int playerSize = playerPos->getSize();

    // int playerXPos = player->getPlayerPos().pos->x;
    // int playerYPos = player->getPlayerPos().pos->y;

    //int foodXpos = food->getFoodpos().pos->x;
    //int foodYpos = food ->getFoodpos().pos->y;

    int boardSizeX = gameMechs->getBoardSizeX(); // Board sizes are called from gameMechs
    int boardSizeY = gameMechs->getBoardSizeY();

    bool drewSnakeSegment, drewFood;

    MacUILib_clearScreen();   

    for (int i = 0; i< boardSizeX; i++){
        MacUILib_printf("#"); // Prints the top border
    }
    MacUILib_printf("\n");

    for (row = 1; row< boardSizeY-1; row++)
    {
        for (column = 0; column <boardSizeX; column++)
        {
            drewSnakeSegment = false;
            drewFood = false;

            // iterate through the playerpos array list to print all segments out

            for (int k = 0; k<playerSize; k++){
                objPos thisSeg = objPos(playerPos->getElement(k));
                if (row == thisSeg.pos->y && column == thisSeg.pos->x){
                    MacUILib_printf("%c", thisSeg.getSymbol());
                    drewSnakeSegment = true;
                    break;
                }
            }

            if (drewSnakeSegment){
                continue;
            }

            for (int k = 0; k<5; k++){
                objPos foodPos = objPos(food->getFoodpos()->getElement(k));
                if (row == foodPos.pos->y && column == foodPos.pos->x){
                    MacUILib_printf("%c", foodPos.getSymbol());
                    drewFood = true;
                    break;
                }
            }

            if (drewFood){
                continue;
            }


            
            // at the end of the for loop. do something to determine whether to continue with the if else of move on to next iteration

            if (column == 0){
                MacUILib_printf("#"); // Left border
            }
            else if (column == boardSizeX-1)
            {
                MacUILib_printf("#\n"); // Right border
            }
            // else if (playerXPos == column && playerYPos == row)
            // {
            //     MacUILib_printf("%c", player->getPlayerPos().getSymbol()); // Prints player symbol
            // }
            // else if (column == foodXpos && row == foodYpos)
            // {
            //     MacUILib_printf("%c", food->getFoodpos().getSymbol()); //food symbol
            // }
            /*
            else{
                for (int i = 0; i<5; i++){
                    if(itemBin[i].x == column && itemBin[i].y == row){
                        MacUILib_printf("%c", itemBin[i].symbol);
                        item = 1;
                        break;
                    }
                }
                if (item == 0){
                    MacUILib_printf(" ");
                } 
            }*/
           else{
                MacUILib_printf(" "); // If nothing occupies that position print a blank space
           }
        }
    }
    for (int i = 0; i< boardSizeX; i++){
        MacUILib_printf("#"); // Prints the bottom border
    }
    MacUILib_printf("\n");

    MacUILib_printf("Input:%c   ASCII:%d\n", gameMechs->getInput(), gameMechs->getInput());
    
    //===DEBUGGING===
    MacUILib_printf("Score:%d\n", gameMechs->getScore()); //CHECKING FOR SCORE INCREMENTATION
    for (int i = 0; i<player->getPlayerPos()->getSize(); i++){
        MacUILib_printf("Food position:[%d,%d]\n",food->getFoodpos()->getElement(i).pos->x, food->getFoodpos()->getElement(i).pos->y); //DISPLAY FOOD POSITION
    }
    MacUILib_printf("Snake size: %d\n", player->getPlayerPos()->getSize());
    for (int i = 0; i<player->getPlayerPos()->getSize(); i++){
        MacUILib_printf("Snake segment [%d]: (%d, %d, %c)\n",i,  player->getPlayerPos()->getElement(i).pos->x, player->getPlayerPos()->getElement(i).pos->y, player->getPlayerPos()->getElement(i).symbol);
    }
    //===DEBUGGING===
    
    MacUILib_printf("===End of Game Message===\n");

    if (gameMechs->getLoseFlagStatus()==true)
    {
        MacUILib_printf("Sorry you have lost game\n");
        gameMechs->setExitTrue();
    }
    else
    {
        if (gameMechs->getExitFlagStatus() == true)
        {
            
            MacUILib_printf("You are exiting the game without winning!");
        }
        
    }
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();  
    // Idk if we're supposed to clear the screen here

    delete gameMechs; //deleting gamemechs 
    delete player;
    delete food;

    MacUILib_uninit();
    
   
}
