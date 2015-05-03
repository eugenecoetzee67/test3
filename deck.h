/**************************************************************/
/* File Information: Striata sample code                      */
/* Deck class C++ header file                                 */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/
#ifndef Deck_h
#define Deck_h

#include "cardgameglobals.h"
#include "cardgameutils.h"
#include "card.h"

class Deck{
private:
    std::vector<Card> cards; /*Cards are stored by default in "standard" increasing id (and value) order with the ACE of SPADE last card in the pack*/
    void buildStandardDeck(void);
public:
    Deck();
    virtual int drawTopCardValue(void);
    virtual Card drawTopCard(void); 
    virtual void shuffleDeck(bool resetSeed);
    virtual void resetToFullDeck(void);
    virtual void showDeck(void);
    virtual bool checkIfFullDeck(void);
    virtual ~Deck(){}
};

#endif


