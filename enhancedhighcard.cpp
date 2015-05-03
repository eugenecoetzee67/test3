/**************************************************************/
/* File Information: Striata sample code                      */
/* EnhancedHighCard class C++ implementation file             */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/

#include "enhancedhighcard.h"

bool EnhancedHighCard::Play(bool paramShuffleBeforePlay)
    { if(paramShuffleBeforePlay) this->Shuffle();
      int dealerCardGameValue = playDeck.drawTopCardValue(); 
      int playerCardGameValue = playDeck.drawTopCardValue();
      return (dealerCardGameValue < playerCardGameValue);  
    }

GameOutcome EnhancedHighCard::Play(bool paramShuffleBeforePlay, GameVariation paramGameVariation, int paramHighCard)
    { if(paramShuffleBeforePlay) this->Shuffle();
      this->PrepareForGame(paramGameVariation, paramHighCard);
      Card dealerCard = playDeck.drawTopCard();
      Card playerCard = playDeck.drawTopCard();
#ifdef DEBUG
      std::cout<< "\ndealerCard Id = "<< dealerCard.getId()<< " playerCard Id = "<< playerCard.getId()<< std::endl; 
#endif
      return this->ChooseWinner(dealerCard, playerCard);
    }
  
GameOutcome EnhancedHighCard::ChooseWinner(const Card& dealerCard, const Card& playerCard)
    { bool trumpCardGame = ((trumpCardId) > 0 && (trumpCardId <= STANDARD_DECK_SIZE));
      if(trumpCardGame)
          {if(dealerCard.getId() == trumpCardId) return GameOutcome::LOSE;
           if(playerCard.getId() == trumpCardId) return GameOutcome::WIN;
          }  
      switch(gameVariation)
         {case GameVariation::TIE:
              if(dealerCard.getName() == playerCard.getName())
                  {return GameOutcome::TIE;
                  }
          case GameVariation::SUITSHIGH:
              if(dealerCard.getName() == playerCard.getName())
                  {if(static_cast<int>(dealerCard.getSuit()) < static_cast<int>(playerCard.getSuit())) return GameOutcome::WIN;
                   else return GameOutcome::LOSE;
                  }
          case GameVariation::ANOTHERCARD:
              if(dealerCard.getName() == playerCard.getName())
                  this->Play(false,gameVariation,trumpCardId);

          case GameVariation::DEFAULT:
               if(dealerCard.getGameValue() < playerCard.getGameValue()) return GameOutcome::WIN;
               else return GameOutcome::LOSE;
               break;
         }
      return GameOutcome::LOSE;
    }

void EnhancedHighCard::Shuffle(void)
    { playDeck.shuffleDeck(true);      
    }
void EnhancedHighCard::ShowDeck(void)
    { playDeck.showDeck();
    }
void EnhancedHighCard::PrepareForGame(GameVariation paramGameVariation, int paramTrumpCardId)
    {trumpCardId = paramTrumpCardId;
     switch(paramGameVariation)
         {case GameVariation::TIE:
          case GameVariation::SUITSHIGH:
          case GameVariation::ANOTHERCARD: 
               if(paramGameVariation != gameVariation)
                   {playDeck.resetToFullDeck();
                    this->Shuffle();
                    gameVariation = paramGameVariation;
                   }
               break;
          case GameVariation::DEFAULT:
               this->Shuffle(); 
               gameVariation = paramGameVariation;
               break;
         }
    }
