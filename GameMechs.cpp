#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    MacUILib_init(); // Need to initialize in every file if we use a MacUILib function
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    MacUILib_init(); // Need to initialize in every file if we use a MacUILib function
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //at this moment, NO, no heap members
    MacUILib_uninit(); 
}
//copy constructors
GameMechs:: GameMechs(const GameMechs &game)
{
    input = game.input;
    exitFlag = game.exitFlag;
    loseFlag = game.loseFlag;
    score = game.score;
    boardSizeX = game.boardSizeX;
    boardSizeY = game.boardSizeY;
}
GameMechs& GameMechs::operator= (const GameMechs &game)
{
    if (this != &game)
    {
        this->input = game.input;
        this->exitFlag = game.exitFlag;
        this->loseFlag = game.loseFlag;
        this->score = game.score;
        this->boardSizeX = game.boardSizeX;
        this->boardSizeY = game.boardSizeY;
	}
	return *this;
}
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() 
{
    
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here