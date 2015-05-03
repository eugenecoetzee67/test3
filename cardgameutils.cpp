/**************************************************************/
/* File Information: Striata sample code                      */
/* CardGame class C++ implementation file                     */
/* Version Control: to applicable standard                    */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>  */
/* Copyright Notice: to applicable standard                   */
/**************************************************************/

#include "cardgameutils.h"

/*uses clock_gettime with nanosecond resolution as a seed to srand*/

void CardGameUtils::lib_ShuffleDefault(void)
    {
#ifdef LINUX
     struct timespec timeSeedRec;
     clock_gettime(CLOCK_REALTIME, &timeSeedRec);
     srand(timeSeedRec.tv_nsec);
#endif
    }
