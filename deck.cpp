/**************************************************************/
/* File Information: Striata sample code                      */
/* Deck class C++ implementation file                         */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/

#include "deck.h"
#include "cardgame.h"

Deck::Deck()
    {cards.reserve(STANDARD_DECK_SIZE);
     buildStandardDeck();
    }

void Deck::buildStandardDeck(void)
    {cards.push_back(Card(1,CardName::TWO,CardSuit::CLUB));cards.push_back(Card(2,CardName::TWO,CardSuit::DIAMOND));
     cards.push_back(Card(3,CardName::TWO,CardSuit::HEART));cards.push_back(Card(4,CardName::TWO,CardSuit::SPADE));
     cards.push_back(Card(5,CardName::THREE,CardSuit::CLUB));cards.push_back(Card(6,CardName::THREE,CardSuit::DIAMOND));
     cards.push_back(Card(7,CardName::THREE,CardSuit::HEART));cards.push_back(Card(8,CardName::THREE,CardSuit::SPADE));
     cards.push_back(Card(9,CardName::FOUR,CardSuit::CLUB));cards.push_back(Card(10,CardName::FOUR,CardSuit::DIAMOND));
     cards.push_back(Card(11,CardName::FOUR,CardSuit::HEART));cards.push_back(Card(12,CardName::FOUR,CardSuit::SPADE));
     cards.push_back(Card(13,CardName::FIVE,CardSuit::CLUB));cards.push_back(Card(14,CardName::FIVE,CardSuit::DIAMOND));
     cards.push_back(Card(15,CardName::FIVE,CardSuit::HEART));cards.push_back(Card(16,CardName::FIVE,CardSuit::SPADE));
     cards.push_back(Card(17,CardName::SIX,CardSuit::CLUB));cards.push_back(Card(18,CardName::SIX,CardSuit::DIAMOND));
     cards.push_back(Card(19,CardName::SIX,CardSuit::HEART));cards.push_back(Card(20,CardName::SIX,CardSuit::SPADE));
     cards.push_back(Card(21,CardName::SEVEN,CardSuit::CLUB));cards.push_back(Card(22,CardName::SEVEN,CardSuit::DIAMOND));
     cards.push_back(Card(23,CardName::SEVEN,CardSuit::HEART));cards.push_back(Card(24,CardName::SEVEN,CardSuit::SPADE));
     cards.push_back(Card(25,CardName::EIGHT,CardSuit::CLUB));cards.push_back(Card(26,CardName::EIGHT,CardSuit::DIAMOND));
     cards.push_back(Card(27,CardName::EIGHT,CardSuit::HEART));cards.push_back(Card(28,CardName::EIGHT,CardSuit::SPADE));
     cards.push_back(Card(29,CardName::NINE,CardSuit::CLUB));cards.push_back(Card(30,CardName::NINE,CardSuit::DIAMOND));
     cards.push_back(Card(31,CardName::NINE,CardSuit::HEART));cards.push_back(Card(32,CardName::NINE,CardSuit::SPADE));
     cards.push_back(Card(33,CardName::TEN,CardSuit::CLUB));cards.push_back(Card(34,CardName::TEN,CardSuit::DIAMOND));
     cards.push_back(Card(35,CardName::TEN,CardSuit::HEART));cards.push_back(Card(36,CardName::TEN,CardSuit::SPADE));
     cards.push_back(Card(37,CardName::JACK,CardSuit::CLUB));cards.push_back(Card(38,CardName::JACK,CardSuit::DIAMOND));
     cards.push_back(Card(39,CardName::JACK,CardSuit::HEART));cards.push_back(Card(40,CardName::JACK,CardSuit::SPADE));
     cards.push_back(Card(41,CardName::QUEEN,CardSuit::CLUB));cards.push_back(Card(42,CardName::QUEEN,CardSuit::DIAMOND));
     cards.push_back(Card(43,CardName::QUEEN,CardSuit::HEART));cards.push_back(Card(44,CardName::QUEEN,CardSuit::SPADE));
     cards.push_back(Card(45,CardName::KING,CardSuit::CLUB));cards.push_back(Card(46,CardName::KING,CardSuit::DIAMOND));
     cards.push_back(Card(47,CardName::KING,CardSuit::HEART));cards.push_back(Card(48,CardName::KING,CardSuit::SPADE));
     cards.push_back(Card(49,CardName::ACE,CardSuit::CLUB));cards.push_back(Card(50,CardName::ACE,CardSuit::DIAMOND));
     cards.push_back(Card(51,CardName::ACE,CardSuit::HEART));cards.push_back(Card(52,CardName::ACE,CardSuit::SPADE));
    }
int Deck::drawTopCardValue(void)
    {if(!cards.empty())
        {int cardGameValue = cards.back().getGameValue();
         cards.pop_back();
         return cardGameValue;
        }  
     else throw IllegalCardOperationException();
    }

Card Deck::drawTopCard(void)
    {if(!cards.empty())
        {Card topCard  = cards.back();
         cards.pop_back();
         return topCard;
        }  
     else throw IllegalCardOperationException();
    }

void Deck::shuffleDeck(bool resetSeed)
    {if(resetSeed) CardGameUtils::lib_ShuffleDefault(); 
     int randomRange = cards.size();
     for(auto i = 0; i < randomRange; i++)
        {int newPosition = rand() % randomRange;
         std::swap(cards[i],cards[newPosition]); 
        }
    }

void Deck::resetToFullDeck(void)
    {cards.clear();
     buildStandardDeck();
    }

void Deck::showDeck(void)
    {std::cout<<std::endl;
     for(auto &i : cards)
        {std::cout <<" |card id = " << i.getId()<< " value = "<< i.getGameValue();
        }
     std::cout<<std::endl;
    }
bool Deck::checkIfFullDeck(void)
    {int sumOfIds = 0;
     for(auto &i : cards)
        {sumOfIds += i.getId();
        }
    return (sumOfIds == (STANDARD_DECK_SIZE*(STANDARD_DECK_SIZE + 1))/2); /* series formula for som 1+2+3+4+...52 */
    }

