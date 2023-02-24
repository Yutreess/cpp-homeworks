// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5
// Section:    A
// Date:       10/22/2018
// File:       main.cpp
// Description:


#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include "header.h"
using namespace std;

int main()
{
  ifstream answers;
  //ifstream noun;
  // Declaring Candidates
  Candidate Krusty;
  Candidate Quimby;

  int numAnswers; // Number of answers in answers.dat
  int answerNumber; // Line in answers.dat to use for answer[]
  int numNouns;
  int currentQuestion = 1;
  int maxQuestions = 8;
  char question[Q_AND_A_LENGTH + 1]; // Added 1 to give room for the null character at the end
  char noun[MAX_WORD_LENGTH];

  // Assigning Names to Candidates
  strcpy(Krusty.name, "Krusty");
  strcpy(Quimby.name, "Quimby");
  answers.open("answers.dat");
  answers >> numAnswers;

  // Retrieve number of Nouns
  countNouns(numNouns);

  do
  {
    // Get Question from the user.
    cout << "Question " << currentQuestion << ": ";
    cin.getline(question, Q_AND_A_LENGTH);

    // Seed Answer Line to use
    srand(time(0));
    answerNumber = (rand() % numAnswers) + 1;

    // Candidates
    if(currentQuestion % 2 == 1)
    {
      setAnswer(answerNumber, Krusty);
      chooseNoun(numNouns, noun);
      // Print their Answer
      //replaceNouns(Krusty.answer);
      cout << Krusty.name << ": " << Krusty.answer << endl;
      // Set their Score
      calcScore(question, Krusty.answer, Krusty.score);
      // Print their Score
      cout << "Score: " << Krusty.score << endl;
      answers.clear();
    }
    else
    {
      setAnswer(answerNumber, Quimby);
      chooseNoun(numNouns, noun);
      // Print their Answer
      //replaceNouns(Quimby.answer);
      cout << Quimby.name << ": " << Quimby.answer << endl;
      // Set their Score
      calcScore(question, Quimby.answer, Quimby.score);
      // Print their Score
      cout << "Score: " << Quimby.score << endl;
      answers.clear();
    }
    currentQuestion++;
  }
  while(currentQuestion <= maxQuestions);

  answers.close();
  //noun.close();
  return 0;
}
