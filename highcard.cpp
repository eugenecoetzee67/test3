/**************************************************************/
/* File Information: Striata sample code                      */
/* HighCard class C++ implementation file                     */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/

#include "highcard.h"

bool HighCard::Play(void)
    { int dealerCard = rand() % STANDARD_DECK_SIZE + 1;
      int playerCard = rand() % STANDARD_DECK_SIZE + 1;
      return ( dealerCard < playerCard);
    }

bool HighCard::Play(bool paramShuffleBeforePlay)
    { if(paramShuffleBeforePlay) this->Shuffle();
      int dealerCard = rand() %  STANDARD_DECK_SIZE + 1;
      int playerCard = rand() %  STANDARD_DECK_SIZE + 1;
      return ( dealerCard < playerCard);
    }
void HighCard::Shuffle(void)
    { CardGameUtils::lib_ShuffleDefault();
    }
