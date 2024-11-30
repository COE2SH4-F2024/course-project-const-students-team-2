#include "objPosArrayList.h"

#include <iostream>

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

    if (listSize >= arrayCapacity){
            throw std::overflow_error("[ERROR]: Array full, can't insert");
        return;
    }


    for (int i = listSize; i >0; i--){
            aList[i] = aList[i-1]; // Shift every element in the list back one spot

    }                              // The first element is in index [0] and [1] after this

    aList[0] = thisPos; // Index [0] gets overwritten with new element
    listSize++;



}

void objPosArrayList::insertTail(objPos thisPos)
{

    if (listSize >= arrayCapacity){
        throw std::overflow_error("[ERROR]: Array full, can't insert");
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
    else{
        throw std::underflow_error("[ERROR]: Array empty, can't remove element");
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0){
        listSize--;
    }
    else{
        throw std::underflow_error("[ERROR]: Array empty, can't remove element");
    }
}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize > 0){
        return aList[0];
    }
    else{
        throw std::out_of_range("[ERROR]: Array empty, no head element");
    }
    
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize > 0){
        return aList[listSize-1];
    }
    else{
        throw std::out_of_range("[ERROR]: Array empty, no tail element");
    }
}

objPos objPosArrayList::getElement(int index) const
{
    
    if (index >= listSize || index < 0){
        throw std::out_of_range("[ERROR]: Index out of range");
    }

    return aList[index]; //handling outofbounds (according to DR.chen's video)
}




