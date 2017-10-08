//
//  main.cpp
//  PRG-7-19-Magic-8-Ball
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that simulates a Magic 8 Ball, which is a fortune-telling toy that displays
//  a random response to a yes or no question. In the student sample programs for this book,
//  you will find a file named 8_ball_responses.txt. The file contains 12 responses, such
//  as "I don't think so", "Yes, of course!", "I'm not sure", and so forth. The program
//  should read the responses from the file into an array or vector. It should prompt the
//  user to ask a question, and then display one of the responses, randomly selected from the
//  array or vector. The program should repeat until the user is ready to quit.
//
//  Contents of 8_ball_responses.txt
//  --------------------------------
//  Yes, of course!
//  Without a doubt, yes.
//  You can count on it.
//  For sure!
//  Ask me later.
//  I'm not sure.
//  I can't tell you right now.
//  I'll tell you after my nap.
//  No way!
//  I don't think so.
//  Without a doubt, no.
//  The answer is clearly NO.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INT_ARRAY_SIZE = 12;

void generateArray(string[]);
int generateRandomNumber();
void generateResponse(const string[], int, string &);

int main()
{
    string strArrayResponses[INT_ARRAY_SIZE];
    string strResponse;
    string strExit;
    
    int intResponseNumber;
    
    generateArray(strArrayResponses);
    
    while(strExit != "exit" && strExit != "Exit" && strExit != "EXIT")
    {
        cout << "Generating response, please wait...\n";
        
        do
        {
            intResponseNumber = generateRandomNumber();
        } while(intResponseNumber > 12);
        generateResponse(strArrayResponses, intResponseNumber, strResponse);
        cout << strResponse << endl;
        cout << "Type exit to quit, or press any key\n"
        << "another response: ";
        cin >> strExit;
    }
    
    return 0;
}

void generateArray(string responseArray[])
{
    string strTemp;
    
    ifstream responseFile;
    
    responseFile.open("/Users/bluebackdev/Desktop/CodeBlocks/For Github/07-Arrays and Vectors/PRG-7-19-Magic-8-Ball/PRG-7-19-Magic-8-Ball/8_ball_responses.txt");
    if(!responseFile)
    {
        cout << "File open Failure!";
    }
    
    for(int arraySize = 0 ; arraySize < INT_ARRAY_SIZE ; arraySize++)
    {
        getline(responseFile, strTemp);
        //responseFile >> strTemp;
        responseArray[arraySize] = strTemp;
        //cout << chrLetter << endl;
        //cout << strTemp << endl;
        
        responseFile.clear();
    }
    
    responseFile.close();
}

int generateRandomNumber()
{
    int intResult;
    int intTempTime;
    
    float fltClock;
    
    intTempTime = time(0);
    
    //Test when intTempTime is the same as time(0)
    //It is sometimes false and falls through
    //With no returned value
    while(intTempTime == time(0))
    {
        while(intTempTime != time(0))
        {
            fltClock = time(0);
            
            unsigned seed = time(0);
            
            srand(seed);
            
            intResult = rand() % 12;
            
            return intResult;
        }
    }
    return 0;
}

void generateResponse(const string responseArray[], int intRandom, string &refResponse)
{
    refResponse = responseArray[intRandom];
}

