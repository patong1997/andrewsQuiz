package com.example.cppquiz;

/**
 * Wrapper for our c++ com.example.cppquiz.CppQuiz.Quiz class
 */
public class Quiz {

  private long quizPtr = 0;
  private long currentQuestionPtr;
  int quizSize = 0;
  private String currentQuestion;
  private String optionOne;
  private String optionTwo;
  private String optionThree;
  private String optionFour;
  private char correctOption;

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

  public void setQuizSize(){
    quizSize = getQuizSize( quizPtr );
  }

  public void setNextQuestion(){
    currentQuestionPtr = getNextQuestion( this.quizPtr );
  }

  public void setQuestionText(){
    currentQuestion = getQuestionText( currentQuestionPtr );
  }
  public void setOptionOne(){
    optionOne = getOptionOne( currentQuestionPtr );
  }
  public void setOptionTwo(){
    optionTwo = getOptionTwo( currentQuestionPtr );
  }
  public void setOptionThree(){
    optionThree = getOptionThree( currentQuestionPtr );
  }
  public void setOptionFour(){
    optionFour = getOptionFour( currentQuestionPtr );
  }
  public void setCorrectOption(){
    correctOption = getCorrectOption(currentQuestionPtr);
  }

  public void finalize(){
    destroyNativeInstance( this.quizPtr );
  }

  /**
   * Formats our question and its options into a string for output
   */
  public String questionText(){
    return currentQuestion + "\n" + optionOne + "\n" + optionTwo + "\n" + optionThree + "\n"
      + optionFour + "\n";
  }

  /**
   * Checks if the chosen option is correct
   */
  public Boolean isCorrect( char chosenOption ){
    if ( chosenOption == correctOption ){
      return true;
    } else return false;
  }

}
