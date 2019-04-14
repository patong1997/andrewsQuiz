#include "Question.h"

Option::Option( string theOption, char letter ){
  this->theOption = theOption;
  this->letter = letter;
}

Question::Question( string theQuestion, vector<Option*> * options, char correct){
  this->theQuestion = theQuestion;
  this->options = options;
  correctLetter = correct;
}

Question::~Question() {
  auto it = options->begin();
  auto end = options->end();
  while ( it != end ){
    delete *it;
    it++;
  }
  delete options;
}

string Question::getQuestion(){
  return theQuestion;
}

vector<Option*> * Question::getOptions(){
  return options;
}

char Question::getCorrectLetter(){
  return correctLetter;
}

Question* Quiz::getNextQuestion(){
  if ( index != questions->size() ){
    index++;
    return questions->at(index);
  }
}

void Quiz::addQuestion( Question * question ){
  questions->push_back(question);
}

Quiz::Quiz(){

  questions = new vector<Question*>();

  Option * quesOneOpOne = new Option( "2", 'A' );
  Option * quesOneOpTwo = new Option( "3", 'B' );
  Option * quesOneOpThree = new Option( "4", 'C' );
  Option * quesOneOpFour = new Option( "5", 'D' );
  vector<Option*> * quesOneOptions = new vector<Option*>();
  quesOneOptions->push_back(quesOneOpOne);
  quesOneOptions->push_back(quesOneOpTwo);
  quesOneOptions->push_back(quesOneOpThree);
  quesOneOptions->push_back(quesOneOpFour);
  Question * firstQuestion = new Question( "1+1", quesOneOptions, 'A');

  Option * quesTwoOpOne = new Option( "2", 'A' );
  Option * quesTwoOpTwo = new Option( "3", 'B' );
  Option * quesTwoOpThree = new Option( "4", 'C' );
  Option * quesTwoOpFour = new Option( "5", 'D' );
  vector<Option*> * quesTwoOptions = new vector<Option*>();
  quesTwoOptions->push_back(quesTwoOpOne);
  quesTwoOptions->push_back(quesTwoOpTwo);
  quesTwoOptions->push_back(quesTwoOpThree);
  quesTwoOptions->push_back(quesTwoOpFour);
  Question * secondQuestion = new Question( "1+2", quesTwoOptions, 'B');

  Option * quesThreeOpOne = new Option( "2", 'A' );
  Option * quesThreeOpTwo = new Option( "3", 'B' );
  Option * quesThreeOpThree = new Option( "4", 'C' );
  Option * quesThreeOpFour = new Option( "5", 'D' );
  vector<Option*> * quesThreeOptions = new vector<Option*>();
  quesThreeOptions->push_back(quesThreeOpOne);
  quesThreeOptions->push_back(quesThreeOpTwo);
  quesThreeOptions->push_back(quesThreeOpThree);
  quesThreeOptions->push_back(quesThreeOpFour);
  Question * thirdQuestion = new Question( "2+2", quesThreeOptions, 'C');

  Option * quesFourOpOne = new Option( "2", 'A' );
  Option * quesFourOpTwo = new Option( "3", 'B' );
  Option * quesFourOpThree = new Option( "4", 'C' );
  Option * quesFourOpFour = new Option( "5", 'D' );
  vector<Option*> * quesFourOptions = new vector<Option*>();
  quesFourOptions->push_back(quesFourOpOne);
  quesFourOptions->push_back(quesFourOpTwo);
  quesFourOptions->push_back(quesFourOpThree);
  quesFourOptions->push_back(quesFourOpFour);
  Question * fourthQuestion = new Question( "2+3", quesFourOptions, 'D');

  index = 0;

  questions->push_back(firstQuestion);
  questions->push_back(secondQuestion);
  questions->push_back(thirdQuestion);
  questions->push_back(fourthQuestion);

  size = questions->size();

}

Quiz::~Quiz() {
  auto it = questions->begin();
  auto end = questions->end();
  while ( it != end ){
    delete *it;
    it++;
  }
  delete questions;
}
