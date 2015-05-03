/**************************************************************/
/* File Information: Striata sample code                      */
/* Card class C++ header file                                 */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/
#ifndef Card_h
#define Card_h

enum class CardName{TWO=2,THREE=3,FOUR=4,FIVE=5,SIX=6,SEVEN=7,EIGHT=8,NINE=9,TEN=10,JACK=10,QUEEN=10,KING=10,ACE=11};/*Face values based on Black Jack rules */
enum class CardSuit{CLUB=1,DIAMOND=2,HEART=3,SPADE=4};/*Suite values based on poker rules */

class Card{
private:
    int id; /*Unique id for every card in the deck ranging from 1 to 52 */
    CardName name;
    CardSuit suit;
    int gameValue;/*Actual value used in a game based on specific game rules. Defaults to the id value.*/
public:
    Card(int paramId,CardName paramCardName, CardSuit paramCardSuit):id(paramId),
        name(paramCardName),suit(paramCardSuit),gameValue(paramId){} 
    void setGameValue(int paramValue){gameValue = paramValue;};
    int getId() const{return id;}
    CardName getName(void) const{return name;}
    CardSuit getSuit(void)const{return suit;}
    int getFaceValue(void)const{return static_cast<int>(name);}
    int getGameValue(void)const{return gameValue;}   
};
#endif
