/**************************************************************/
/* File Information: Striata sample code                      */
/* Main card game C++ header file                             */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/

#ifndef ICardGame_h
#define ICardGame_h

class Deck; //forward declaration
enum class GameVariation{DEFAULT,TIE,SUITSHIGH,ANOTHERCARD};
enum class GameOutcome{TIE,WIN,LOSE};

class ICardGame{
public:
    virtual bool Play(bool paramShuffleBeforePlay) = 0;
    virtual void Shuffle(void) = 0;
    virtual void ShowDeck(void) = 0;
    virtual GameOutcome Play(bool paramShuffleBeforePlay, GameVariation paramGameVariation, int paramHighCard) = 0;
    virtual void PrepareForGame(GameVariation paramGameVariation, int paramHighCardId) = 0;
    virtual void SetDeck(Deck& paramDeck) = 0;     
};

class ICardMultiDeckGame{      
public:
    virtual void Shuffle(int deckNo) = 0;
    virtual void ShowDeck(int deckNo) = 0;
    virtual GameOutcome Play(int deckNo, bool paramShuffleBeforePlay, GameVariation paramGameVariation, int paramHighCard) = 0;
    virtual void PrepareForGame(int deckNo,GameVariation paramGameVariation, int paramHighCardId) = 0;
    virtual void ChangeDeckSize(int deckNo) = 0;
};

class IllegalCardOperationException: public std::exception
    {virtual const char* what() const throw()
        {return "An Illegal Card Operation Occured";
        }
    };

class IllegalGameMethodException: public std::exception
    {virtual const char* what() const throw()
        {return "An Illegal Call To Method Occured";
        }
    };

#endif
