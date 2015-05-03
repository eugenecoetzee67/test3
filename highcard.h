/**************************************************************/
/* File Information: Striata sample code                      */
/* HighCard class C++ header file                             */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/
#ifndef HighCard_h
#define HighCard_h

#include "cardgameglobals.h"
#include "cardgameutils.h"
#include "cardgame.h"

class HighCard:public ICardGame{
public:
    bool Play(void);
    bool Play(bool paramShuffleBeforePlay);
    void Shuffle(void);
    void ShowDeck(void){std::cout << MESSAGE_NOT_IMPLEMENTED;};
    GameOutcome Play(bool paramShuffleBeforePlayGame, GameVariation paramGameVariation, int paramHighCard){throw IllegalGameMethodException();};
    void PrepareForGame(GameVariation paramGameVariation, int paramHighCardId){throw IllegalGameMethodException();};
    void SetDeck(Deck& paramDeck){throw IllegalGameMethodException();}
};

#endif
