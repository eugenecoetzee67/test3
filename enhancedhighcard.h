/**************************************************************/
/* File Information: Striata sample code                      */
/* EnhancedHighCard class C++ header file                     */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/
#ifndef EnhancedHighCard_h
#define EnhancedHighCard_h

#include "cardgame.h"

class EnhancedHighCard:public ICardGame{
private:
Deck& playDeck;
GameVariation gameVariation;
int trumpCardId;
GameOutcome ChooseWinner(const Card& dealerCard, const Card& cardplayerCard);
public:
    EnhancedHighCard(Deck& paramPlayDeck):playDeck(paramPlayDeck){this->PrepareForGame(GameVariation::DEFAULT,INVALID_ID);}
    bool Play(bool paramShuffleBeforePlay); 
    void Shuffle(void);
    void ShowDeck(void);
    GameOutcome Play(bool paramShuffleBeforePlayGame, GameVariation paramGameVariation, int paramHighCard);
    void PrepareForGame(GameVariation paramGameVariation, int paramHighCardId);
    void SetDeck(Deck& paramDeck){playDeck = paramDeck;}
};

#endif
