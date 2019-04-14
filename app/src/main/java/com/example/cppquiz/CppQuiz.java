package com.example.cppquiz;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class CppQuiz extends AppCompatActivity {

  long ourQuiz;

  // Used to load the 'native-lib' library on application startup.
  static {
    System.loadLibrary("quiz-lib");
  }

  @Override
  protected void onCreate(Bundle savedInstanceState) {


    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);

    // Example of a call to a native method
    TextView tv = findViewById(R.id.sample_text);
    tv.setText("filler text");

    Quiz newQuiz = new Quiz();
  }

}
