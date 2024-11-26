#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

#define HEIGHT 10
#define WIDTH 20

bool exitFlag;

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

}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    int row,column = 0;
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
            /*else if (player.x == column && player.y == row){
                MacUILib_printf("%c", player.symbol);
            }
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
