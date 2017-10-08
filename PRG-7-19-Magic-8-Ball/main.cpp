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
#include <random>

using namespace std;

const int INT_ARRAY_SIZE = 12;

void generateArray(string[]);
int generateRandomNumber();
string generateResponse(const string[], const int);

int main()
{
    string strArrayResponses[INT_ARRAY_SIZE];
    string strQuestion;
    string strResponse;
    string strExit;
    
    int intResponseNumber;
    
    // Populate array once before loop starts
    generateArray(strArrayResponses);
    
    // Use while loop, don't need do/while since strExit will never be 'exit' on launch
    while(strExit != "exit" && strExit != "Exit" && strExit != "EXIT")
    {
        // Use getline to get full question string
        cout << "Enter your question:\n";
        getline(cin, strQuestion);
        
        // Output this message to let user know the number is generating
        cout << "Generating response, please wait...\n";
        
        // Call function to generate random number
        intResponseNumber = generateRandomNumber();
        
        // Use random number generated as array indesx to pull response
        // from file-generated response array
        strResponse = generateResponse(strArrayResponses, intResponseNumber);
        
        // Repeat question back to the user before answering question
        cout << "In response to your question:\n\"" << strQuestion << "\"\nThe Magic 8-Ball says:\n";
        
        // Respond with randomly selected array value
        cout << strResponse << endl;
        
        // Allow user to loop the function and ask another question
        cout << "Type exit to quit, or enter any key\n"
        << "another response: ";
        
        // Use getline otherwise line break will break the loop
        getline(cin, strExit);
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
        responseArray[arraySize] = strTemp;
        responseFile.clear();
    }
    
    responseFile.close();
}

int generateRandomNumber()
{
    int intResult;
    
    // Use random_device to generate seed
    random_device rd;
    
    // Use seed to set Mersenne twister engine
    mt19937 engine(rd());
    
    // Define distribution and type
    uniform_int_distribution<> distribution(0, 11);
    
    // Generate a result in range of distribution with MTE engine
    intResult = distribution(engine);
    
    return intResult;
}

// Constants here since there won't be any modification of the values, just reading
string generateResponse(const string responseArray[], const int intRandom)
{
    string strResponse;
    
    strResponse = responseArray[intRandom];
    
    return strResponse;
}

