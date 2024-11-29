#include "objPos.h"

objPos::objPos() //default constructor 
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym) //additional constructor 
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule
//      - Destructor DONE
//      - Copy Assignment DONE
//      - Copy Operator DONE
// Add to objPos.h too

objPos:: ~objPos()
{
	delete pos;
    pos = nullptr;
}
objPos::objPos(const objPos &op)
{
    //copy constructor
    pos = new Pos;
    pos->x = op.pos->x;
    pos->y = op.pos->y;
    symbol = op.symbol;
    
}
objPos& objPos::operator= (const objPos &op)
{
    // Copy assignment Operator
	if (this != &op){
        this->pos->x = op.pos->x;
        this->pos->y = op.pos->y;
        this->symbol = op.symbol;
	}
	return *this;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
