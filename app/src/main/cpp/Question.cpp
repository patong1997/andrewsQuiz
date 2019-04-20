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
    return questions->at(index-1);
  }
}

/**
 * TODO: Change to load in quiz from a file.
 */
Quiz::Quiz(){

  questions = new vector<Question*>();

  Option * quesOneOpOne = new Option( "A Little", 'A' );
  Option * quesOneOpTwo = new Option( "Not At All", 'B' );
  Option * quesOneOpThree = new Option( "Very", 'C' );
  Option * quesOneOpFour = new Option( "Who?", 'D' );
  vector<Option*> * quesOneOptions = new vector<Option*>();
  quesOneOptions->push_back(quesOneOpOne);
  quesOneOptions->push_back(quesOneOpTwo);
  quesOneOptions->push_back(quesOneOpThree);
  quesOneOptions->push_back(quesOneOpFour);
  Question * firstQuestion = new Question( "How cool is Andrew?", quesOneOptions, 'C');

  Option * quesTwoOpOne = new Option( "21", 'A' );
  Option * quesTwoOpTwo = new Option( "22", 'B' );
  Option * quesTwoOpThree = new Option( "23", 'C' );
  Option * quesTwoOpFour = new Option( "50", 'D' );
  vector<Option*> * quesTwoOptions = new vector<Option*>();
  quesTwoOptions->push_back(quesTwoOpOne);
  quesTwoOptions->push_back(quesTwoOpTwo);
  quesTwoOptions->push_back(quesTwoOpThree);
  quesTwoOptions->push_back(quesTwoOpFour);
  Question * secondQuestion = new Question( "How old is Andrew?", quesTwoOptions, 'B');

  Option * quesThreeOpOne = new Option( "Nobody", 'A' );
  Option * quesThreeOpTwo = new Option( "Bill Gates", 'B' );
  Option * quesThreeOpThree = new Option( "Some Asshole", 'C' );
  Option * quesThreeOpFour = new Option( "A Talking Elephant", 'D' );
  vector<Option*> * quesThreeOptions = new vector<Option*>();
  quesThreeOptions->push_back(quesThreeOpOne);
  quesThreeOptions->push_back(quesThreeOpTwo);
  quesThreeOptions->push_back(quesThreeOpThree);
  quesThreeOptions->push_back(quesThreeOpFour);
  Question * thirdQuestion = new Question( "Who created this quiz?", quesThreeOptions, 'C');

  Option * quesFourOpOne = new Option( "7", 'A' );
  Option * quesFourOpTwo = new Option( "4", 'B' );
  Option * quesFourOpThree = new Option( "9", 'C' );
  Option * quesFourOpFour = new Option( "10000", 'D' );
  vector<Option*> * quesFourOptions = new vector<Option*>();
  quesFourOptions->push_back(quesFourOpOne);
  quesFourOptions->push_back(quesFourOpTwo);
  quesFourOptions->push_back(quesFourOpThree);
  quesFourOptions->push_back(quesFourOpFour);
  Question * fourthQuestion = new Question( "What would you rate Andrew from 1-10?", quesFourOptions, 'D');

  Option * quesFiveOpOne = new Option( "Absolutely", 'A' );
  Option * quesFiveOpTwo = new Option( "I've used better", 'B' );
  Option * quesFiveOpThree = new Option( "Unfortunately", 'C' );
  Option * quesFiveOpFour = new Option( "This is trash", 'D' );
  vector<Option*> * quesFiveOptions = new vector<Option*>();
  quesFiveOptions->push_back(quesFiveOpOne);
  quesFiveOptions->push_back(quesFiveOpTwo);
  quesFiveOptions->push_back(quesFiveOpThree);
  quesFiveOptions->push_back(quesFiveOpFour);
  Question * fifthQuestion = new Question( "Is this the greatest app you've ever used?", quesFiveOptions, 'A');

  Option * quesSixOpOne = new Option( "No", 'A');
  Option * quesSixOpOne = new Option( "No", 'B');
  Option * quesSixOpOne = new Option( "No", 'C');
  Option * quesSixOpOne = new Option( "Absolutely no", 'D');
  vector<Option*> * quesSixOptions = new vector<Option*>();
  quesSixOptions->push_back(quesSixOpOne);
  quesSixOptions->push_back(quesSixOpTwo);
  quesSixOptions->push_back(quesSixOpThree);
  quesSixOptions->push_back(quesSixOpFour);
  Question * sixthQuestion = new Question("If the average volume of the penis is 2.53% relative to the body, does it make it gay on girls?", quesSixOptions, 'D');
  index = 0;

  questions->push_back(firstQuestion);
  questions->push_back(secondQuestion);
  questions->push_back(thirdQuestion);
  questions->push_back(fourthQuestion);
  questions->push_back(fifthQuestion);
  questions->push_back(sixthQuestion);
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
