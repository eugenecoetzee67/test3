==========
Overview
==========
The sample code is based on a real world scenario where a given card game has been developed as a concrete class named HighCard and deployed over a large existing client code base. The HighCard class has been implemented and used as illustrated in the code below:      

class HighCard{
public: 
    HighCard(){}
    ~HighCard(){}
    bool Play()
        {int i = rand() % 52 + 1;
         int j = rand() % 52 + 1;
         return ( i < j );
        }
};

int main()
{HighCard card;  
 if(card.Play())
    {puts("win");
    }
 else
    {puts("lose");
    }
 return 0;
}

The base functionality of class HighCard is implemented through method Play() with two cards drawn from a 52 card deck and with the highest card winning. 

New requirements for class HighCard have been specified and they include a range of expanded capabilities with support for the following new features:

* Supporting ties when the face value of the two cards are the same. 
* Allowing for ties to be resolved by giving the different suits precedence. 
* Support for "wild cards" trumping all other cards. 
* Support for multiple decks in a game. 
* Support for decks with less than 52 cards.

The above changes in user requirements necessitates code refactoring and a new flexible, open-ended design that is discussed in the "Discussion" section below. 

==================
Basic instructions
==================

* UML diagram of the basic design is included in cardgame_uml.pdf.

* Main unit testing program is included as samplecode_test.cpp.

* Executable running the unit tests is included as program samplecode_test.

* Code was tested and compiled on Linux OS with compiler options:
        g++ -std=c++0x -Wall samplecode_test.cpp deck.cpp cardgame.cpp highcard.cpp enhancedhighcard.cpp cardgameutils.cpp -o samplecode_test -lrt

(note - binaries are  linked againt Linux real time extension library using -lrt linker directive)

* A simple Makefile is included. Run 'make' command from command line to compile.  

==========
Discussion
==========
Design choices and considerations are briefly discussed here. Please refer to the UML diagram in cardgame_uml.pdf to follow this discussion.
 
Compatibility with existing client code was considered important. Code was refactored in such a way that existing client code using the HighCard class does not have to be modified although it is necessary to recompile against the new implementation to ensure binary compatibility.
 
Rapidly changing and/or future user requirement flexibility and re-usability was considered. It was clear from the incremental changes in user requirements that a design that makes it easy to change and add functionality to future versions of the game will be important. It was decided to use a combination of the following design patterns to realise this goal:

* decorator: in order to easily modify and extend various new versions of the HighCard game the decorator structural design pattern with polymorphic pointers to a "decorated object" that implements the required functionality is used. The ICardGame interface (see icard.h) defines the basic methods supported by a card game object.

* bridge/adapter: the requirement for support for multiple decks can best be accommodated using a wrapper class (CardGame in cardgame.h) that maps a multi-deck interface to the ICardGame interface and also encapsulates a collection of card decks. The ICardMultiDeckGame interface (see icard.h) defines the basic methods supported by a multi-deck card game. It must be noted that the interface methods described by ICardMultDeckGame are similar to methods described by ICardGame but with an added index parameter to select a specific deck.

* delegation/abstraction: OS compatibility layer issues are handled through a single delegated class CardGameUtils (see cardgameutils.h) where all OS specific methods are mapped to the correct implementation using compiler directives.         

The decorated classes HighCard and EnhancedHighCard (see highcard.h and enhancedhighcard.h) used in the design inherits methods from pure abstract (interface) class ICardGame and are then forced to implement (by contract) all the methods they inherit from the interface. Specific/concrete classes HighCard and EnhancedHighCard both implements ICardGame. Objects of HighCard and EnhancedHighCard may be contained by the client class CardGame that acts as a wrapper or container as discussed above in accordance with the decorator pattern. 

The CardGame container class also acts as a container for a vector of card decks that can then be passed through and controlled separately from the "game logic" implemented by the concrete game or decorated classes. 

The design contains a strong degree of cohesion (well defined interfaces with method calls working together to achieve a very specific functionality) and only the minimum required coupling. The relationships and coupling between classes are defined by encapsulation and containment relationship as indicated in the UML diagram. In particular it must be note that class Deck (deck.h) contains a vector of Card objects, that class CardGame (cardgame.h) contains a vector of Deck objects and that class CardGame contains a pointer to an object of a class that implements ICardGame.   

==========
Unit tests
==========
The unit tests in samplecode_test.cpp were used for development and testing purposes and are divided into two main unit test classes:

* TestBasicHighCard - test the basic refactored HighCard class to ensure that it works exactly like the old HighCard class. Test the new shuffle functions. Test the CardGame wrapper class with HighCard. 
 
* TestEnhancedHighCard - test coupled classes Card and Deck. Test the new EnhancedHighCard class. Test the CardGame wrapper class with EnhancedHighCard.

It should noted that card game outcomes are by design unpredictable and that care must be taken to construct unit tests that are predictable and repeatable. The software relies on the random function to generate numbers used to simulate card draws in the various versions of Play() for this purpose. Most test have been constructed using the srand(1) function call in order to ensure that subsequent function calls to rand() through Play() will be repeatable and predictable can be therefore be tested. This however does not apply to versions of Play() using the shuffleBeforePlay = true parameter where Play() may return either true/win or false/lose around 50% of the time.       

=======================
Coding style/convention
=======================
The following coding conventions has been used in naming of classes, methods and variable:

* Class names - UpperCamelCase
* Method names in interfaces - UpperCamelCase
* Method names - lowerCamelCase
* Variable names - lowerCamelCase
* Global variable names - UPPERCASE

Exactly 4 x white spaces have been used for indentation. In methods and functions all opening/closing curly brackets are aligned so as to guarantee readibility.  

===================
Memory leak tests
===================
A Valgrind report analysing the executable code in samplecode_test is included in file memleaktest.txt. No memory leaks were detected.

=====================================
Additional notes on build environment
=====================================
Built using g++ compiler on Ubuntu Linux 12.04 LTS output from: g++ -v 
Using built-in specs.
COLLECT_GCC=g++
Target: i686-linux-gnu
Thread model: posix
gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5)

glibc++ version output from: ldconfig -p | grep stdc++
libstdc++.so.6 (libc6) => /usr/lib/i386-linux-gnu/libstdc++.so.6
