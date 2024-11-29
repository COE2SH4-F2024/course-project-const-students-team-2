#include "objPosArrayList.h"
#include "stdio.h" // Check if this library needs to be deleted after testing

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];

}


objPosArrayList::objPosArrayList(const objPosArrayList &list){
    // Copy Assignment
    
    listSize = list.getSize();
    arrayCapacity = list.arrayCapacity;
    aList = new objPos[arrayCapacity];
    printf("List: [");
    for (int i = 0; i<listSize; i++){
        aList[i] = list.aList[i];
        printf("(%d, %d, '%c'), ", aList[i].pos->x, aList[i].pos->y, aList[i].symbol);
    }
    printf("]\n");
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
            this->aList[i] = list.aList[i];
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
        arrayCapacity += ARRAY_MAX_CAP;
        objPos* newList = new objPos[arrayCapacity];
        for (int i = 0; i<listSize; i++){
            newList[i] = aList[i];
        }
        delete[] aList;
        objPos* aList = new objPos[arrayCapacity];
        aList = newList;
        delete[] newList;
    }
    for (int i = listSize -1; i >=0; i--){
            aList[i+1] = aList[i];
        }
    printf("Adding element [%d] (x:%d, y:%d)\n", 0, aList[0].pos->x, aList[0].pos->y);
    aList[0] = thisPos;
    listSize++;


     printf("List: [");
    for (int i = 0; i<listSize; i++){
        printf("(%d, %d, '%c'), ", aList[i].pos->x, aList[i].pos->y, aList[i].symbol);
    }
    printf("]\n");
}

void objPosArrayList::insertTail(objPos thisPos)
{
    
    if (arrayCapacity <= listSize){
        arrayCapacity += ARRAY_MAX_CAP;
        objPos* newList = new objPos[arrayCapacity];
        for (int i = 0; i<listSize; i++){
            newList[i] = aList[i];
        }
        delete[] aList;
        objPos* aList = new objPos[arrayCapacity];
        aList = newList;
        delete[] newList;
    }

    printf("Adding element [%d] (x:%d, y:%d)\n", listSize, aList[listSize].pos->x, aList[listSize].pos->y);
    aList[listSize] = thisPos;
    listSize++;
    
    printf("List: [");
    for (int i = 0; i<listSize; i++){
        printf("(%d, %d, '%c'), ", aList[i].pos->x, aList[i].pos->y, aList[i].symbol);
    }
    printf("]\n");
}

void objPosArrayList::removeHead()
{
    for (int i = 0; i <listSize-1; i++){
            aList[i] = aList[i+1];
    }
    listSize--;
    printf("Deleting element [%d] (x:%d, y:%d)\n", listSize, aList[listSize].pos->x, aList[listSize].pos->y);
    delete &aList[listSize];
    printf("List: [");
    for (int i = 0; i<listSize; i++){
        printf("(%d, %d, '%c'), ", aList[i].pos->x, aList[i].pos->y, aList[i].symbol);
    }
    printf("]\n");
}

void objPosArrayList::removeTail()
{
    listSize--;
    printf("Deleting element [%d] (x:%d, y:%d)\n", listSize, aList[listSize].pos->x, aList[listSize].pos->y);
    delete &aList[listSize];

    printf("List: [");
    for (int i = 0; i<listSize; i++){
        printf("(%d, %d, '%c'), ", aList[i].pos->x, aList[i].pos->y, aList[i].symbol);
    }
    printf("]\n");
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
    return aList[index];
    /// WATCH VIDEO, HANDLE EXCEPTIONS
}

