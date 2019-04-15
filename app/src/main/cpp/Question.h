#ifndef QUESTION_H 
#define QUESTION_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Option{

public:
  string theOption;
  char letter;
  Option( string theOption, char letter );
};

class Question{

private:
  string theQuestion;
  vector<Option*> * options;
  char correctLetter;

public:
  Question( string theQuestion, vector<Option*> * options, char correctLetter);
  ~Question();
  string getQuestion();
  vector<Option*> * getOptions();
  char getCorrectLetter();
};

class Quiz{

public:
    vector<Question*> * questions;
    int index;
    int size;
    Quiz();
    ~Quiz();
    void addQuestion( Question * question );
    Question * getNextQuestion();
};


#endif QUESTION_H