/**************************************************************/
/* File Information: Striata sample code                      */
/* Cardgame class C++ header file                             */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/
#ifndef CardGame_h
#define CardGame_h

#include "deck.h"
#include "icard.h"

class CardGame: public ICardGame, ICardMultiDeckGame{
private:
    ICardGame* cardGameObj;
    std::vector<Deck> decks;
public:
    CardGame(ICardGame* paramCardGameObj);
    virtual bool Play(bool paramShuffleBeforePlay);
    virtual void Shuffle(void);
    virtual void ShowDeck(void);
    virtual void SetDeck(Deck& paramDeck);     
    virtual GameOutcome Play(bool paramShuffleBeforePlayGame, GameVariation paramGameVariation, int paramHighCard);
    virtual void PrepareForGame(GameVariation paramGameVariation, int paramHighCardId);
    virtual ~CardGame(){};
    virtual void Shuffle(int deckNo);
    virtual void ShowDeck(int deckNo);
    virtual GameOutcome Play(int deckNo, bool paramShuffleBeforePlay, GameVariation paramGameVariation, int paramHighCard);
    virtual void PrepareForGame(int deckNo,GameVariation paramGameVariation, int paramHighCardId);
    virtual void ChangeDeckSize(int deckNo);

};

#endif
