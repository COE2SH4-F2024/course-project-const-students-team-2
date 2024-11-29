#include "objPosArrayList.h"
#include "stdio.h" // Check if this library needs to be deleted after testing

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = 200;
    aList = new objPos[arrayCapacity];

}


objPosArrayList::objPosArrayList(const objPosArrayList &list){
    // Copy Assignment
    
    listSize = list.getSize();
    arrayCapacity = list.arrayCapacity;
    aList = new objPos[arrayCapacity];
    for (int i = 0; i<listSize; i++){
        aList[i] = list.getElement(i);
    }
}


objPosArrayList& objPosArrayList::operator= (const objPosArrayList &list)
{
    // Copy Operator
	if (this != &list){
        
        this->listSize = list.getSize();
        this->arrayCapacity = list.arrayCapacity;
        delete[] aList;
        this->aList = new objPos[this->arrayCapacity];
        for (int i = 0; i<listSize; i++){
            this->aList[i] = list.getElement(i);
        }
	}
	return *this;
}

objPosArrayList::~objPosArrayList()
{
    // Destructor
    
    delete[] aList;
    aList = nullptr;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (arrayCapacity <= listSize){
        printf("Array Increase\n");
        arrayCapacity += 200;
        aList = new objPos[arrayCapacity];
    }
    //printf("%d\n", listSize -1);
    for (int i = listSize -1; i >=0; i--){
            aList[i+1] = aList[i];
        }
    aList[0] = thisPos;
   // printf("%d\n", aList[0].pos->x);
    //printf("%d\n", aList[0].pos->y);
    //printf("%c\n", aList[0].symbol);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    
    if (arrayCapacity <= listSize){
        objPos* newList = aList;
        delete[] aList;
        arrayCapacity += 200;
        aList = new objPos[arrayCapacity];
        delete[] newList;
    }
    
    aList[listSize] = thisPos;
    listSize++;
    
}

void objPosArrayList::removeHead()
{
    for (int i = 0; i <listSize-1; i++){
            aList[i] = aList[i+1];
    }
    delete[] &aList[listSize-1];
    listSize--;
}

void objPosArrayList::removeTail()
{
    delete &aList[listSize-1];
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index]; //handling outofbounds (according to DR.chen's video)
}

