/**************************************************************/
/* File Information: Striata sample code                      */
/* Cardgame class C++ header file                             */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/
#ifndef CardGameUtils_h
#define CardGameUtils_h

#include <iostream>
#include <math.h>  

//Non-portable OS specific functions belong here

#define LINUX

class CardGameUtils{
public:
    static void lib_ShuffleDefault(void); //static library method names starts with lib_  
};

#endif
