/**************************************************************/
/* File Information: Striata sample code                      */
/* CardGame class C++ implementation file                     */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/

#include "cardgame.h"

// Standard CardGame wrapper API
 
CardGame::CardGame(ICardGame* paramCardGameObj):cardGameObj(paramCardGameObj)
    {decks.reserve(20);
    }

bool CardGame::Play(bool paramShuffleBeforePlay)
    {if(!dynamic_cast<ICardGame*>(cardGameObj)) throw IllegalGameMethodException();
     else return cardGameObj->Play(paramShuffleBeforePlay);
    }
void CardGame::Shuffle(void)
    {if(!dynamic_cast<ICardGame*>(cardGameObj)) throw IllegalGameMethodException();
     else return cardGameObj->Shuffle(); 
    }
void CardGame::ShowDeck(void)
    {if(!dynamic_cast<ICardGame*>(cardGameObj)) throw IllegalGameMethodException();
     else return cardGameObj->ShowDeck();
    }
GameOutcome CardGame::Play(bool paramShuffleBeforePlayGame, GameVariation paramGameVariation, int paramHighCard)
    {if(!dynamic_cast<ICardGame*>(cardGameObj)) throw IllegalGameMethodException();
     else return cardGameObj->Play(paramShuffleBeforePlayGame, paramGameVariation, paramHighCard);
    }
void CardGame::PrepareForGame(GameVariation paramGameVariation, int paramHighCard)
    {if(!dynamic_cast<ICardGame*>(cardGameObj)) throw IllegalGameMethodException();
     else return cardGameObj->PrepareForGame(paramGameVariation, paramHighCard);
    }
void CardGame::SetDeck(Deck& paramDeck)
    {decks.push_back(paramDeck);
    }

// Multideck CardGame bridge/adapter API

void CardGame::ShowDeck(int deckNo)
    {//TODO
     if(unsigned(deckNo) < decks.size() && deckNo >= 0) decks[deckNo].showDeck();
     else throw IllegalCardOperationException();
    }

void CardGame::Shuffle(int deckNo)
    {//TODO
    }

GameOutcome CardGame::Play(int deckNo, bool paramShuffleBeforePlay, GameVariation paramGameVariation, int paramHighCard)
    {//TODO
     return GameOutcome::LOSE;
    }
 
void CardGame::PrepareForGame(int deckNo,GameVariation paramGameVariation, int paramHighCardId)
    {//TODO
    }

void CardGame::ChangeDeckSize(int deckNo)
    {//TODO
    } 
