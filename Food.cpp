#include "Food.h"

Food:: Food()
{
    foodPos.setObjPos(0,0,'o');
}

Food:: ~Food()
{
    //deconstructor
}

void Food::generateFood(objPos blockOff)
{
    srand(time(NULL));    
    
    int boardx = 30; 
    int boardy = 15; 
    
    int firstmatch = 0;
    
    while(!firstmatch)
    {
        int xcoord = rand() % (boardx - 2) + 1;
        int ycoord = rand() % (boardy - 2) + 1;

        foodPos.setObjPos(xcoord,ycoord,'o');

        if(foodPos.isPosEqual(&blockOff) == true) //if playerpos matches foodpos, generate new coord
        {
            continue;
        }
        else
        {
            firstmatch = 1;
        }
        
    }

    
}

objPos Food::getFoodpos() const
{
    return foodPos;
    
}

