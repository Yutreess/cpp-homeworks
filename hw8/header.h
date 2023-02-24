// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5
// Section:    A
// Date:       10/22/2018
// File:       header.h
// Description:

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;

// CONSTANTS

const int Q_AND_A_LENGTH = 700;
const int MAX_WORD_LENGTH = 20;
const int NOUN = 6;

// STUCTS

struct Candidate
{
  char name[20];
  int score = 0;
  char answer[Q_AND_A_LENGTH + 1];
};

// FUNCTIONS

// Description:  Generates an answer c-string
// Precondition: ifstream is connected to answers.dat and nouns.dat files
// Postcondition:
void setAnswer(const int answerNumber, Candidate & cand);

// Description:
// Precondition:
// Postcondition:
void countNouns(int & numNouns);

// Description:
// Precondition:
// Postcondition:
void chooseNoun(const int numNouns, char noun[]);

// Description:
// Precondition:
// Postcondition:
void replaceNouns(char candAnswer[]); // Mine

// Description:  Calculate the score for an answer
// Precondition:
// Postcondition:
void calcScore(char question[], char candAnswer[], int & score);

#endif
