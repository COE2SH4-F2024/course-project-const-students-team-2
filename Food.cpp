#include "Food.h"

Food:: Food()
{
    foodPos.setObjPos(0,0,'o');
}

Food:: ~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));
    
    // int i, j; 
    // int firstmatch, secondmatch, symbolmatch;     
    // int length = my_strlen(str);
    int boardx = 30; 
    int boardy = 15; 
    
    int firstmatch = 0;
    
    while(!firstmatch)
    {
        int xcoord = rand() % (boardx - 2) + 1;
        int ycoord = rand() % (boardy - 2) + 1;

        if(foodPos.isPosEqual(&blockOff) == true)
        {
            continue;
        }
        else
        {
            firstmatch = 1;
        }
    }

    // for (i = 0; i < listSize; i++) 
    // {
    //     firstmatch = 0;

    //     while (!firstmatch) 
    //     {
    //         // Generate candidate x and y coordinates
            

    //         int xcoord = rand() % (xRange - 2) + 1;
    //         int ycoord = rand() % (yRange - 2) + 1;
    //         int charindx = rand() % (length);
    //         //generating a random integer index in appropriate range
            

            
    //         if (xcoord == playerPos -> x && ycoord == playerPos -> y) 
    //         {
    //             continue;  // Generate a new candidate if it matches the player                
                
    //         }

            
    //         secondmatch = 0;
    //         symbolmatch = 0; 

    //         for (j = 0; j < i; j++) 
    //         {  // Only check previously assigned items
    //             if (list[j].x == xcoord && list[j].y == ycoord) 
    //             {
    //                 secondmatch = 1;                    
    //                 break;
    //             }
    //             if(list[j].symbol == str[charindx])
    //             {
    //                 symbolmatch = 1; 
    //                 break;
    //             }
    //         }

            
    //         if (!secondmatch && !symbolmatch) 
    //         {
            
    //             list[i].x = xcoord;
    //             list[i].y = ycoord;
    //             list[i].symbol = str[charindx];
    //             firstmatch = 1;
    //         }
    //     }
    // }
}

objPos Food::getFoodpos() const
{
    return foodPos;
    
}

