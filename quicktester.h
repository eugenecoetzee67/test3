/***************************************************************/
/* File Information: QuikTester C++ header File                */
/* Abstract base class for lightweight unit tests              */
/* Version Control: rev a, released on 2015-01-11              */
/* Programmer Contact: Eugene Coetzee <eugene@reedflute.com>   */
/* Copyright Notice: Eugene Coetzee                            */
/***************************************************************/

#ifndef QuickTester_h
#define QuickTester_h
#include <iostream>
#include <string>

class QuickTester{
private:
    int testRunsTotal;
    int testRunsOk;
    int status;
    std::string resultsMessage;
protected:
    virtual void updateResults(std::string descriptionStr, std::string messageStr, bool success)
        {testRunsTotal++; 
         resultsMessage += "Test (" + std::to_string(testRunsTotal) + ") " + descriptionStr + " " + messageStr;
         if(success)
             {testRunsOk++;
              resultsMessage += " passed\n"; 
             } 
         else 
             {resultsMessage += " FAILED\n";
              status = -1;
             } 
        }
public:
    QuickTester(): testRunsTotal(0), testRunsOk(0), status(0), resultsMessage("\nTESTING RESULTS\n"){}
    virtual void run(void) = 0;
    virtual void setTestSuiteName(const std::string testSuiteName){resultsMessage += testSuiteName + "\n";}
    virtual void printResults(void)
        {resultsMessage = resultsMessage + "Passed (" + std::to_string(testRunsOk) + "/" + std::to_string(testRunsTotal) + ") tests"  + "\n";
         std::cout << resultsMessage << std::endl;
        }
    virtual int getStatus(void){return status;}
};
#endif
