package com.example.cppquiz;

/**
 * Wrapper for our c++ com.example.cppquiz.CppQuiz.Quiz class
 */
public class Quiz {

  private long quizPtr = 0;
  private long currentQuestionPtr;
  int quizSize = 0;
  String currentQuestion;
  String optionOne;
  String optionTwo;
  String optionThree;
  String optionFour;
  char correctOption;
  int score = 0;

  private native long createQuiz( /* params */ );
  private native long getNextQuestion( long nativePtr );
  private native String getQuestionText( long questionPtr );
  private native String getOptionOne( long questionPtr );
  private native String getOptionTwo( long questionPtr );
  private native String getOptionThree( long questionPtr );
  private native String getOptionFour( long questionPtr );
  private native int getQuizSize( long quizPtr );
  private native char getCorrectOption( long questionPtr );
  private native void destroyNativeInstance( long p_native_ptr );

  public Quiz(){
    this.quizPtr = createQuiz( /*params */ );
    setQuizSize();
  }

  /**
   * Advances to the next question in the quiz
   */
  public void moveToNextQuestion(){
    setNextQuestion();
    setQuestionText();
    setOptionOne();
    setOptionTwo();
    setOptionThree();
    setOptionFour();
    setCorrectOption();
  }

  private void setQuizSize(){
    quizSize = getQuizSize( quizPtr );
  }
  private void setNextQuestion(){
    currentQuestionPtr = getNextQuestion( this.quizPtr );
  }
  private void setQuestionText(){
    currentQuestion = getQuestionText( currentQuestionPtr );
  }
  private void setOptionOne(){
    optionOne = getOptionOne( currentQuestionPtr );
  }
  private void setOptionTwo(){
    optionTwo = getOptionTwo( currentQuestionPtr );
  }
  private void setOptionThree(){
    optionThree = getOptionThree( currentQuestionPtr );
  }
  private void setOptionFour(){
    optionFour = getOptionFour( currentQuestionPtr );
  }
  private void setCorrectOption(){
    correctOption = getCorrectOption(currentQuestionPtr);
  }

  public void finalize(){
    destroyNativeInstance( this.quizPtr );
  }

  /**
   * Checks if the chosen option is correct
   */
  public Boolean checkAnswer( char chosenOption ){
    if ( chosenOption == correctOption ){
      score++;
      return true;
    } else return false;
  }

  public String getResults(){

    String resultString = "You got " + Integer.toString(score) + " / " + quizSize + " .\n";
    if ( score == quizSize ){
      resultString = resultString + " GOOD SHIT ";
    } else if (score > (quizSize - 1) ){
      resultString = "GOOD";
    } else if ( score > (quizSize - 2) ){
      resultString = resultString + " You aight ";
    } else {
      resultString = resultString + " ehhhh....... ";
    }

    return resultString;
  }

}
