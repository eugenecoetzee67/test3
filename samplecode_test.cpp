/***************************************************************/
/* File Information: Striata sample code                       */
/* Testing program used to test and refactor the original code */
/* Version Control: to applicable standard                     */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>   */
/* Copyright Notice: to applicable standard                    */
/***************************************************************/

/* IMPORTANT NOTES: 
The card game classes depends on random function and therefore every 
test call to Play() method should be preceded with srand(1) to ensure 
a consistent seed value for repeatable and testable results.

Results from Play() method may vary whin used with shuffleBeforePlay
parameter. These 50/50 test results are reported as passes.*/

/*Using light weight unit-tester. */
#include "quicktester.h" 

#include "card.h"
#include "deck.h"
#include "highcard.h"
#include "enhancedhighcard.h"
#include "cardgame.h"

class TesterBasicHighCard: public QuickTester{ 
private:
    int totalPlays;
    int expectedWins;
    double acceptableDeviation;
    void testBasicUseOriginal(void);
    void testStatisticalBasicUseOriginal(void);
    void testBasicUse(void);
    void testStatisticalBasicUse(void);
    void testBasicUseWithShuffle(void);
    void testStatisticalBasicUseWithShuffle(void);
    void testBasicUseThroughCardGameWrapper(void);
public:
    TesterBasicHighCard():totalPlays(1000),expectedWins(500),acceptableDeviation(10.0){}
    TesterBasicHighCard(int paramTotalPlays, int paramExpectedWins, double paramAcceptableDeviation):
    totalPlays(paramTotalPlays),expectedWins(paramExpectedWins),acceptableDeviation(paramAcceptableDeviation){}
    void run();
};

void TesterBasicHighCard::run()
    {testBasicUse();
     testStatisticalBasicUse(); 
     testBasicUseWithShuffle();
     testStatisticalBasicUseWithShuffle();
     testBasicUseThroughCardGameWrapper();
    };


/*Test basic use of class HighCard to maintain compatibility with the old client code (function main). */
void TesterBasicHighCard::testBasicUse()
    {HighCard testGame;
     srand(1);
     if(testGame.Play()) updateResults("testBasicUse","won the first hand around 50% of the time",false);
     else updateResults("testBasicUse","lost the first hand ALL THE TIME!!!",true);
    }

/*Test basic use of class HighCard through the card game wrapper class*/
void TesterBasicHighCard::testBasicUseThroughCardGameWrapper()
    {HighCard myHighCard;
     CardGame testGame(&myHighCard);
     bool shuffleBeforePlay = true;
     srand(1);
     if(testGame.Play(shuffleBeforePlay)) updateResults("testBasicUseThroughCardGameWrapper (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseThroughCardGameWrapper (chances 50/50)","lost the first hand around 50% of the time",true);
    }

/*Test basic use of class HighCard bring in shuffle to bring variability into first hand win sequence*/
void TesterBasicHighCard::testBasicUseWithShuffle()
    {HighCard testGame;
     bool shuffleBeforePlay = true;
     srand(1);
     if(testGame.Play(shuffleBeforePlay)) updateResults("testBasicUseWithShuffle (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseWithShuffle (chances 50/50)","lost the first hand around 50% of the time",true);
    }

/*Test basic use winning stats of HighCard class*/
void TesterBasicHighCard::testStatisticalBasicUse()
    {HighCard testGame;
     double winPercentageDeviation = 100.0;
     int wins = 0;
#ifdef DEBUG
     std::cout <<"\ntestStatisticalBasicUse - wins in "<< totalPlays<<" plays: ";
#endif
     srand(1);
     for(int i = 1; i <= totalPlays; i++)
         {if(testGame.Play()) wins++;
#ifdef DEBUG
          std::cout << wins <<" ";
#endif
         }
     winPercentageDeviation = fabs(((double(wins-expectedWins))/expectedWins) * 100.0);
     if(winPercentageDeviation < acceptableDeviation)
         updateResults("testStatisticalBasicUse","win percentage devation = " + std::to_string(winPercentageDeviation),true);
     else updateResults("testStatisticalBasicUse","win percentage devation = " + std::to_string(winPercentageDeviation),false);
    }

/*Test basic use winning stats of HighCard class*/
void TesterBasicHighCard::testStatisticalBasicUseWithShuffle()
    {HighCard testGame;
     double winPercentageDeviation = 100.0;
     int wins = 0;
     bool shuffleBeforePlay = true;
#ifdef DEBUG
     std::cout <<"\ntestStatisticalBasicUseWithShuffle - wins in "<< totalPlays<<" plays: ";
#endif
     srand(1);
     for(int i = 1; i <= totalPlays; i++)
         {if(testGame.Play(shuffleBeforePlay)) wins++;
#ifdef DEBUG
          std::cout << wins <<" ";
#endif
         }
     winPercentageDeviation = fabs(((double(wins-expectedWins))/expectedWins) * 100.0);
     if(winPercentageDeviation < acceptableDeviation)
         updateResults("testStatisticalBasicUseWithShuffle","win percentage devation = " + std::to_string(winPercentageDeviation),true);
     else updateResults("testStatisticalBasicUseWithShuffle","win percentage devation = " + std::to_string(winPercentageDeviation),false);
    }
class TesterEnhancedHighCard: public QuickTester{
private:
    int totalPlays;
    int expectedWins;
    double acceptableDeviation;
    void testBasicUseOriginal(void);
    void testTiesBasicUse(void);
    void testStatisticalBasicUse(void);
    void testBasicUseThroughCardGameWrapper(void);
    void testCard(void);
    void testDeck(void);
    void testEmptyDeck(void);
public:
    TesterEnhancedHighCard():totalPlays(1000),expectedWins(500),acceptableDeviation(10.0){}
    TesterEnhancedHighCard(int paramTotalPlays, int paramExpectedWins, double paramAcceptableDeviation):
    totalPlays(paramTotalPlays),expectedWins(paramExpectedWins),acceptableDeviation(paramAcceptableDeviation){}
    void run();
};

void TesterEnhancedHighCard::run()
     {testCard();
      testDeck();
      testEmptyDeck();
      testTiesBasicUse();
      testBasicUseThroughCardGameWrapper();
     };

/*Test support for ties for cards with same value */
void TesterEnhancedHighCard::testTiesBasicUse()
    {Deck myDeck;
     EnhancedHighCard testGame(myDeck);
#ifdef DEBUG
     testGame.ShowDeck();
#endif
     bool shuffleBeforePlay = true;
     srand(1);
     if(testGame.Play(shuffleBeforePlay)) updateResults("testBasicUseSameAsHighCard (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseSameAsHighCard (chances 50/50)","lost the first hand around 50% of the time",true);
     shuffleBeforePlay = false;
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::DEFAULT,-1) == GameOutcome::WIN) 
         updateResults("testBasicUseDefault (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseDefault (chances 50/50)","lost the first hand around 50% of the time",true);
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::TIE,-1) == GameOutcome::WIN) 
         updateResults("testBasicUseTie (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseTie (chances 50/50)","lost the first hand around 50% of the time",true);
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::SUITSHIGH,-1) == GameOutcome::WIN) 
         updateResults("testBasicUseSuitsHigh (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseSuitsHigh (chances 50/50)","lost the first hand around 50% of the time",true);
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::ANOTHERCARD,-1) == GameOutcome::WIN) 
         updateResults("testBasicUseAnotherCard (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseAnotherCard (chances 50/50)","lost the first hand around 50% of the time",true);
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::TIE,15) == GameOutcome::WIN)
         updateResults("testBasicUseTieWithTrumpCard (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseTieWithTrump (chances 50/50)","lost the first hand around 50% of the time",true);
     Deck myDeck2;
     testGame.SetDeck(myDeck2);
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::SUITSHIGH,32) == GameOutcome::WIN)
         updateResults("testBasicUseSuitsHighWithTrumpCard (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseSuitsHighWithTrumpCard (chances 50/50)","lost the first hand around 50% of the time",true);
     srand(1);
     if(testGame.Play(shuffleBeforePlay, GameVariation::ANOTHERCARD,48) == GameOutcome::WIN)
         updateResults("testBasicUseAnotherCardWithTrumpCard (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseAnotherCardWithTrumpCard (chances 50/50)","lost the first hand around 50% of the time",true); 
    }
/*Test basic use of class EnhancedHighCard through the card game wrapper class*/
void TesterEnhancedHighCard::testBasicUseThroughCardGameWrapper()
    {Deck myDeck;
     EnhancedHighCard myEnhancedHighCard(myDeck);
     CardGame testGame(&myEnhancedHighCard);
     bool shuffleBeforePlay = true;
     srand(1);
     if(testGame.Play(shuffleBeforePlay)) updateResults("testBasicUseThroughCardGameWrapper (chances 50/50)","won the first hand around 50% of the time",true);
     else updateResults("testBasicUseThroughCardGameWrapper (chances 50/50)","lost the first hand around 50% of the time",true);
     Deck myDeck2;
     testGame.SetDeck(myDeck2); 
   }

void TesterEnhancedHighCard::testCard()
    {Card myCard(1,CardName::TWO,CardSuit::CLUB);
     if(myCard.getId() == 1) updateResults("testCard","",true);
     else updateResults("testCard","",false); 
     if(myCard.getName() == CardName::TWO) updateResults("testCard","",true);
     else updateResults("testCard","",false); 
     if(myCard.getSuit() == CardSuit::CLUB) updateResults("testCard","",true);
     else updateResults("testCard","",false); 
     if(myCard.getFaceValue() == 2) updateResults("testCard","",true);
     else updateResults("testCard","",false); 
     if(myCard.getGameValue() == 1) updateResults("testCard","",true);
     else updateResults("testCard","",false);
     myCard.setGameValue(101); 
     if(myCard.getGameValue() == 101) updateResults("testCard","",true);
     else updateResults("testCard","",false); 
    }

void TesterEnhancedHighCard::testDeck()
    {Deck myDeck;
     bool resetSeed = false;
     if(myDeck.checkIfFullDeck()) updateResults("testDeckIsFull","",true);
     else updateResults("testDeckIsFull","",false);
     if(myDeck.drawTopCardValue() == 52) updateResults("testDeck","",true);
     else updateResults("testDeck","",false);  
     if(myDeck.drawTopCardValue() == 51) updateResults("testDeck","",true);
     else updateResults("testDeck","",false);
     myDeck.drawTopCardValue();
     myDeck.drawTopCardValue();
     if(myDeck.drawTopCardValue() == 48) updateResults("testDeck","",true);
     else updateResults("testDeck","",false);
     myDeck.resetToFullDeck();
     if(myDeck.drawTopCardValue() == 52) updateResults("testDeck","",true);
     else updateResults("testDeck","",false);
     myDeck.resetToFullDeck();
     myDeck.shuffleDeck(resetSeed);
     if(myDeck.checkIfFullDeck()) updateResults("testDeckIsFull","",true);
     else updateResults("testDeckIsFull","",false);
    }

void TesterEnhancedHighCard::testEmptyDeck()
    {Deck myDeck;
     try
         {for(int i = 1; i <= 60; i++) myDeck.drawTopCardValue();
         }
     catch(IllegalCardOperationException &e)
         {updateResults("testEmptyDeck","",true);
          return;
         }
     catch(...) 
         {std::cout << "Uncaught Exception occurred\n";
         }
     updateResults("testEmptyDeck","",false);  
    }

int main(int argc, char* argv[])
{TesterBasicHighCard myBasicHighCardTester;
 TesterEnhancedHighCard myEnhancedHighCardTester;
  
 myBasicHighCardTester.setTestSuiteName("Basic HighCard game test suite");
 myBasicHighCardTester.run();
 myBasicHighCardTester.printResults();

 myEnhancedHighCardTester.setTestSuiteName("Enhanced HighCard game test suite");
 myEnhancedHighCardTester.run();
 myEnhancedHighCardTester.printResults();
 
 return myEnhancedHighCardTester.getStatus();
}
/******************************************************/
