package com.example.cppquiz;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class CppQuiz extends AppCompatActivity {

  TextView questionText;
  TextView optionOneText;
  TextView optionTwoText;
  TextView optionThreeText;
  TextView optionFourText;
  Button button_A;
  Button button_B;
  Button button_C;
  Button button_D;
  Button butCont;
  Quiz ourQuiz;
  int index;

  private View.OnClickListener continueListener = new View.OnClickListener(){
    @Override
    public void onClick(View v){
      continueButtonClicked();
    }
  };

  private View.OnClickListener button_A_Listener = new View.OnClickListener(){
    @Override
    public void onClick(View v){
      buttonAClicked();
    }
  };

  private View.OnClickListener button_B_Listener = new View.OnClickListener(){
    @Override
    public void onClick(View v){
      buttonBClicked();
    }
  };

  private View.OnClickListener button_C_Listener = new View.OnClickListener(){
    @Override
    public void onClick(View v){
      buttonCClicked();
    }
  };

  private View.OnClickListener button_D_Listener = new View.OnClickListener(){
    @Override
    public void onClick(View v){
      buttonDClicked();
    }
  };

  // Used to load the 'native-lib' library on application startup.
  static {
    System.loadLibrary("quiz-lib");
  }

  @Override
  protected void onCreate(Bundle savedInstanceState) {

    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    questionText = findViewById(R.id.question);
    optionOneText = findViewById(R.id.option_one);
    optionTwoText = findViewById(R.id.option_two);
    optionThreeText = findViewById(R.id.option_three);
    optionFourText = findViewById(R.id.option_four);
    button_A = findViewById(R.id.option_A);
    button_B = findViewById(R.id.option_B);
    button_C = findViewById(R.id.option_C);
    button_D = findViewById(R.id.option_D);
    butCont = findViewById(R.id.cont);

    butCont.setOnClickListener(continueListener);
    button_A.setOnClickListener(button_A_Listener);
    button_B.setOnClickListener(button_B_Listener);
    button_C.setOnClickListener(button_C_Listener);
    button_D.setOnClickListener(button_D_Listener);

    button_A.setClickable(false);
    button_B.setClickable(false);
    button_C.setClickable(false);
    button_D.setClickable(false);

    ourQuiz = new Quiz();

  }

  private void continueButtonClicked(){

    button_A.setBackgroundResource(android.R.drawable.btn_default);
    button_B.setBackgroundResource(android.R.drawable.btn_default);
    button_C.setBackgroundResource(android.R.drawable.btn_default);
    button_D.setBackgroundResource(android.R.drawable.btn_default);

    // Starting the quiz
    if ( index == 0 ){
      setButtonsVisible();
      setOptionsVisible();
      moveToNext();
      flipButtons();
    }
    // Reached the end of the quiz
    else if ( index == ourQuiz.quizSize){
      index++;
      quizOver();
    }
    else if ( index == (ourQuiz.quizSize + 1) ){
      reset();
    }
    else {
      moveToNext();
      flipButtons();
    }

  }

  private void buttonAClicked(){

    if ( ourQuiz.checkAnswer('A') ){
      button_A.setBackgroundColor(Color.GREEN);
      flipButtons();
    } else{
      button_A.setBackgroundColor(Color.RED);
      flipButtons();
    }

  }

  private void buttonBClicked(){

    if ( ourQuiz.checkAnswer('B') ){
      button_B.setBackgroundColor(Color.GREEN);
      flipButtons();
    } else{
      button_B.setBackgroundColor(Color.RED);
      flipButtons();
    }

  }

  private void buttonCClicked(){

    if ( ourQuiz.checkAnswer('C') ){
      button_C.setBackgroundColor(Color.GREEN);
      flipButtons();
    } else{
      button_C.setBackgroundColor(Color.RED);
      flipButtons();
    }

  }

  private void buttonDClicked(){

    if ( ourQuiz.checkAnswer('D') ){
      button_D.setBackgroundColor(Color.GREEN);
      flipButtons();
    } else{
      button_D.setBackgroundColor(Color.RED);
      flipButtons();
    }

  }

  /**
   * Moves on to next question and adjusts the
   * screen accordingly
   */
  private void moveToNext(){

    index++;
    ourQuiz.moveToNextQuestion();
    questionText.setText("Question: " + ourQuiz.currentQuestion);
    optionOneText.setText(ourQuiz.optionOne );
    optionTwoText.setText(ourQuiz.optionTwo);
    optionThreeText.setText(ourQuiz.optionThree);
    optionFourText.setText(ourQuiz.optionFour);

  }

  private void setOptionsVisible(){
    optionOneText.setVisibility(View.VISIBLE);
    optionTwoText.setVisibility(View.VISIBLE);
    optionThreeText.setVisibility(View.VISIBLE);
    optionFourText.setVisibility(View.VISIBLE);
  }

  private void setButtonsVisible(){
    button_A.setVisibility(View.VISIBLE);
    button_B.setVisibility(View.VISIBLE);
    button_C.setVisibility(View.VISIBLE);
    button_D.setVisibility(View.VISIBLE);
  }

  private void setButtonsInvisible(){
    button_A.setVisibility(View.INVISIBLE);
    button_B.setVisibility(View.INVISIBLE);
    button_C.setVisibility(View.INVISIBLE);
    button_D.setVisibility(View.INVISIBLE);
  }

  /**
   * Flips the visibility and activity of the buttons
   */
  private void flipButtons(){

    if (butCont.isClickable()) {
      button_A.setClickable(true);
      button_B.setClickable(true);
      button_C.setClickable(true);
      button_D.setClickable(true);
      butCont.setClickable(false);
      butCont.setVisibility(View.INVISIBLE);
    } else{
      button_A.setClickable(false);
      button_B.setClickable(false);
      button_C.setClickable(false);
      button_D.setClickable(false);
      butCont.setClickable(true);
      butCont.setVisibility(View.VISIBLE);
    }
  }

  private void quizOver(){

    questionText.setText(ourQuiz.getResults());
    optionOneText.setVisibility(View.INVISIBLE);
    optionTwoText.setVisibility(View.INVISIBLE);
    optionThreeText.setVisibility(View.INVISIBLE);
    optionFourText.setVisibility(View.INVISIBLE);
    setButtonsInvisible();
    butCont.setText("Restart");

  }

  private void reset(){

    button_A.setClickable(false);
    button_B.setClickable(false);
    button_C.setClickable(false);
    button_D.setClickable(false);
    butCont.setText("Continue");
    questionText.setText("Ready to try again? Go ahead...");

    ourQuiz = new Quiz();
    index = 0;

  }

}
