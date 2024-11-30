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

    for (int i = 0; i<listSize; i++){
        aList[i] = list.aList[i];
    }
}


objPosArrayList& objPosArrayList::operator= (const objPosArrayList &list)
{
    // Copy Operator
	if (this != &list){
        
        this->listSize = list.getSize();
        this->arrayCapacity = list.arrayCapacity;

        if (list.arrayCapacity > 0) {
            delete[] aList;
            this->aList = new objPos[list.arrayCapacity]; // allocate a different amount of memory for different array sizes

            for (int i = 0; i < list.listSize; i++) {
                this->aList[i] = list.aList[i];
            }
        } 
        else { // if other arrayList is empty
            this->aList = nullptr; 
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



}

void objPosArrayList::insertTail(objPos thisPos)
{

    if (listSize >= arrayCapacity){
        printf("Insert Tail");
        return;
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize > 0){
        for (int i = 0; i <listSize-1; i++){
            aList[i] = aList[i+1]; // Every element gets shifted forward one index
                                   
        }
                                   // Element at head position is overwritten, element at tail is duplicated

        listSize--; // We don't have to delete the duplicated tail element
                    // We just shorten the length of the list and the program ignores the second one
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0){
        listSize--;
    }
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
    return aList[index]; //handling outofbounds (according to DR.chen's video)
}


