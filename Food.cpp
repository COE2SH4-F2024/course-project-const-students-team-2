#include "Food.h"

Food:: Food()
{
    foodBucket = new objPosArrayList();
    
    objPos foodPos = objPos(6,8, 'o'); // normal food

    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);

    objPos specialPos = objPos(10, 12, '!'); // special food
    foodBucket->insertHead(specialPos);
}

Food:: ~Food()
{
    //deconstructor
    delete foodBucket;
}

Food::Food(const Food &f){
    // Copy Assignment
    foodBucket = new objPosArrayList();
    for (int i = 0; i<f.foodBucket->getSize(); i++){
        foodBucket->insertTail(f.getFoodpos()->getElement(i));
    }

}

Food& Food::operator= (const Food &f)
{
    // Copy Operator
	if (this != &f){
        
        delete foodBucket;
        this->foodBucket = new objPosArrayList();
        this->foodBucket = f.foodBucket;
        for (int i = 0; i<f.foodBucket->getSize(); i++){
            foodBucket->insertTail(f.getFoodpos()->getElement(i));
        }
	}
	return *this;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    srand(time(NULL));    

    
    int boardx = 30; 
    int boardy = 15; 

    
    
    bool freeSpace;

    objPos temp = objPos();

    for (int i = 0; i<5; i++)
    { // for each of the 5 food in the bucket
        
        freeSpace = false; // tracks if the space on the game board isn't occupied by a snake segemnt or another food

        while(!freeSpace)
        {
            freeSpace = true;

            int xcoord = rand() % (boardx - 2) + 1;
            int ycoord = rand() % (boardy - 2) + 1;

            if (i == 0){
                temp.setObjPos(xcoord,ycoord,'!'); // special food
            }
            else{
                temp.setObjPos(xcoord,ycoord,'0'); // normal food
            }
            

            for (int j = 0; j<blockOff->getSize(); j++)
            {
                // checking every snake segment
                if (blockOff->getElement(j).isPosEqual(&temp))
                {
                    freeSpace = false; // space is occupied, generate again
                }
            }

            for (int j = 0; j<i; j++){
                // checking every food generated this cycle
                if (foodBucket->getElement(j).isPosEqual(&temp))
                {
                    freeSpace = false;
                }
            }
            
        }
        foodBucket->insertHead(temp); // adding food to bucket if generated successfully
        foodBucket->removeTail();
    }
    
    

    
}

objPosArrayList* Food::getFoodpos() const
{
    return foodBucket;
    
}

