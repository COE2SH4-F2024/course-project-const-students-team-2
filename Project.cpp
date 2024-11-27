#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000



Player* player;
GameMechs* gameMechs;


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
}

void GetInput(void)
{
    gameMechs->getInput();
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();

}

void DrawScreen(void)
{
    int row,column = 0;
    int playerXPos = player->getPlayerPos().pos->x;
    int playerYPos = player->getPlayerPos().pos->y;
    int boardSizeX = gameMechs->getBoardSizeX();
    int boardSizeY = gameMechs->getBoardSizeY();


    MacUILib_clearScreen();   
    for (int i = 0; i< boardSizeX; i++){
        MacUILib_printf("#"); // Prints the top border
    }
    MacUILib_printf("\n");
    for (row = 1; row<gameMechs->getBoardSizeY()-1; row++){
        for (column = 0; column<gameMechs->getBoardSizeX(); column++){
            if (column == 0){
                MacUILib_printf("#"); // Left border
            }
            else if (column == gameMechs->getBoardSizeX()-1){
                MacUILib_printf("#\n"); // Right border
            }
            else if (playerXPos == column && playerYPos == row){
                MacUILib_printf("%c", player->getPlayerPos().getSymbol()); // Prints player symbol
            }
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
                MacUILib_printf(" ");
           }
        }
    }
    for (int i = 0; i< boardSizeX; i++){
        MacUILib_printf("#"); // Prints the bottom border
    }
    MacUILib_printf("\n");

    MacUILib_printf("Input:%c   ASCII:%d\n", gameMechs->getInput(), gameMechs->getInput());

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

    MacUILib_uninit();
    
   
}
