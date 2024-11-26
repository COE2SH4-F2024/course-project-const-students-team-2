#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

#define HEIGHT 10
#define WIDTH 20

bool exitFlag;

Player* player;
GameMechs* testMechs;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;

    testMechs = new GameMechs();
    player = new Player(testMechs);

}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();
}

void DrawScreen(void)
{
    int row,column = 0;
    int xpos = player->getPlayerPos().pos->x;
    int ypos = player->getPlayerPos().pos->y;
    MacUILib_clearScreen();    
    MacUILib_printf("####################\n");
    for (row = 1; row<HEIGHT-1; row++){
        for (column = 0; column<WIDTH; column++){
            if (column == WIDTH-1){
                MacUILib_printf("#\n");
            }
            else if (column == 0){
                MacUILib_printf("#");
            }
            else if (xpos == column && ypos == row){
                MacUILib_printf("%c", player->getPlayerPos().getSymbol());
            }
            /*
            else{
                for (i = 0; i<5; i++){
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
    MacUILib_printf("####################\n");

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
