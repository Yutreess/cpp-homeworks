// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5
// Section:    A
// Date:       10/22/2018
// File:       functions.cpp
// Description:

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include "header.h"

void setAnswer(const int answerNumber, Candidate & cand)
{
  ifstream answers;
  answers.open("answers.dat");
  // Find line where answer is to be taken
  char candAnswer[Q_AND_A_LENGTH + 1];
  for(int i = 1; i <= answerNumber; i++)
  {
    answers.getline(candAnswer, Q_AND_A_LENGTH, '\n');
    strcpy(cand.answer, candAnswer);
  }
  answers.close();
}

void countNouns(int & numNouns)
{
  ifstream nouns;
  char temp[MAX_WORD_LENGTH];
  nouns.open("nouns.dat");
  while(nouns.getline(temp, MAX_WORD_LENGTH))
  {
    numNouns++;
  }
  nouns.close();
}

void chooseNoun(const int numNouns, char noun[])
{
  ifstream nouns;
  //int nounNumber = (rand() % numNouns);
  nouns.open("nouns.dat");
  // Choose noun to use
  cout << "Noun Number: " << (rand() % numNouns) << endl;
  for(int i = 0; i <= (rand() % numNouns); i++)
    nouns >> noun;

  cout << "Chosen Noun: " << noun << endl;
  nouns.close();
}

// My ReplaceNouns
void replaceNouns(char candAnswer[])
{
  srand(time(0));
  //int nounNumber = (rand() % 101) + 1;
  char noun[MAX_WORD_LENGTH];
  ifstream nouns;
  nouns.open("nouns.dat");

  // CHoose noun to use
  //chooseNoun(noun);
  cout << "Chosen noun: " << noun << endl;
  // Replace Noun in the Array
  for(int i = 0; i < Q_AND_A_LENGTH; i++)
  {
    // Find *noun*
    if(candAnswer[i] == '*' && candAnswer[i + 1] == 'n')
    {
      // Replace *noun*
      if(strlen(noun) == NOUN)
      {
        for(int j = i; j < NOUN; j++)
        {
          candAnswer[j] = noun[j - i];
        }
      }
    }
  }
  nouns.close();
}

/* Gabe's Replace Nouns
void replaceNoun(char answer[], char noun[])
{
	bool foundReplace = false;
  //
	int counter = 0;
	int pushFactor = 0;
	for (int i = 0; i < Q_AND_A_LENGTH; i++)
	{
		if (answer[i] == '*')
		{
			counter++;
		}
	}
  for (int i = 0; i < Q_AND_A_LENGTH; i++)
  {
   	if ((answer[i] == '*' && answer[i + 1] == 'n'))
  	{
   		if (strlen(noun) == NOUN)
  		{
  			for (int j = i; j < (i + NOUN); j++)
  			{
  				answer[j] = noun[j - i];
  			}
  			foundReplace = true;
  		}
  		else
  		{
  		  if (strlen(noun) > REPLACE_LENGTH)
  		  {
  		  	foundReplace = true;
  		  	pushFactor = strlen(noun) - REPLACE_LENGTH;
  		  	for (int k = 0; k < pushFactor; k++)
  		  	{
  		  	  for (int j = strlen(answer); j > i + pushFactor; j--)
  		  	  {
  		  	  	swap(answer[j], answer[j + 1]);
  		  	  }
  		  	}
  		  	for (int k = i; k < (i + REPLACE_LENGTH + pushFactor); k++)
  		  	{
   		  		answer[k] = noun[k - i];
  		  	}
  		  }
  		  else if (strlen(noun) < REPLACE_LENGTH)
  		  {
   		  	pushFactor = REPLACE_LENGTH - strlen(noun);
  		  	foundReplace = true;

  		  	for (int j = 0; j < pushFactor; j++)
  		  	{
  		  		for (int k = strlen(noun) + i; k < strlen(answer); k++)
  		  		{
  		  			swap(answer[k], answer[k + 1]);
  		  		}
  		  	}
  		  	for (int h = i; h < ((2 * i) + pushFactor); h++)
  		  	{
  		  	  answer[h] = noun[h - i];
  		    }
  		  }
  		}
   	}
    if (foundReplace)
    {
			cout << answer << endl;
			i = Q_AND_A_LENGTH;
    }
  }
}
*/

void calcScore(char question[], char candAnswer[], int & score)
{
  int charInQuestion = 0;
  int charInAnswer = 0;
  int questionLength = strlen(question);
  int answerLength = strlen(candAnswer);

  for(int i = 97; i <= 122; i++)
  {
    for(int j = 0; j < questionLength; j++)
    {
      if(question[j] == i || question[j] == (i - 32))
      {
        charInQuestion++;
      }
    }
    for(int j = 0; j < answerLength; j++)
    {
      if(candAnswer[j] == i || candAnswer[j] == (i - 32))
      {
        charInAnswer++;
      }
    }
    //cand.score += (charInQuestion - charInAnswer);
    score += (charInQuestion - charInAnswer);
    charInQuestion = 0;
    charInAnswer = 0;
  }
}



// Assume no word is longer than 20 characters
