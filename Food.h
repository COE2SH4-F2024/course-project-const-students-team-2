#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food
{
    private:
        objPosArrayList* foodBucket;        

    public:
        
        Food(); 
        ~Food(); 
        Food(const Food &f);
        Food& operator= (const Food &f);

    
        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodpos() const;         
        
        
};

#endif