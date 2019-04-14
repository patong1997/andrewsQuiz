#include <jni.h>
#include <string>
#include "Question.h"

/**
 * Creates the cpp quiz object and returns it as a memory address
 * for our java wrapper.
 */
 JNIEXPORT extern "C" jlong JNICALL Java_com_example_cppquiz_Quiz_createQuiz
                (
                JNIEnv*   p_jenv
                , jobject   p_jthis
                )
{
    // Convert params from Java types to C++ types if required
    return (jlong) new Quiz();
}

/**
 * Invokes the destructor for our quiz to destroy all dynamically
 * allocated memory.
 */
JNIEXPORT extern "C" void JNICALL Java_com_example_cppquiz_Quiz_destroyNativeInstance
                (
                  JNIEnv*   p_jenv
                , jobject   p_jthis
                , jlong     p_native_ptr
                )
{
    if( p_native_ptr )
        delete (Quiz*)p_native_ptr;
}

/**
 * Retrieves the quiz's next question as a pointer to set our java wrapper's
 * question pointer.
 */
JNIEXPORT extern "C" jlong JNICALL Java_com_example_cppquiz_Quiz_getNextQuestion
        (       JNIEnv*   p_jenv
                , jobject   p_jthis
                , jlong     p_native_ptr
        )
{
    Quiz * ourQuiz = (Quiz*) p_native_ptr;
    Question * nextQuestion = ((Quiz*)p_native_ptr)->getNextQuestion();
    return (jlong) nextQuestion;
}

/**
 * Retrieves the current question's text
 */
JNIEXPORT extern "C" jstring JNICALL Java_com_example_cppquiz_Quiz_getQuestionText
        ( JNIEnv*   p_jenv
                , jobject   p_jthis
                , jlong     p_native_ptr
        )
{
    Question * ourQuestion = (Question*) p_native_ptr;
    return p_jenv->NewStringUTF(ourQuestion->getQuestion().c_str());
}

JNIEXPORT extern "C" jstring JNICALL Java_com_example_cppquiz_Quiz_getOptionOne
  ( JNIEnv*   p_jenv
    , jobject   p_jthis
    , jlong     p_native_ptr
  )
{
  Question * ourQuestion = (Question*) p_native_ptr;
  Option * option = ourQuestion->getOptions()->at(0);
  string optionText = option->letter + ": " + option->theOption;
  return p_jenv->NewStringUTF(optionText.c_str());
}

JNIEXPORT extern "C" jstring JNICALL Java_com_example_cppquiz_Quiz_getOptionTwo
  ( JNIEnv*   p_jenv
    , jobject   p_jthis
    , jlong     p_native_ptr
  )
{
  Question * ourQuestion = (Question*) p_native_ptr;
  Option * option = ourQuestion->getOptions()->at(1);
  string optionText = option->letter + ": " + option->theOption;
  return p_jenv->NewStringUTF(optionText.c_str());
}

JNIEXPORT extern "C" jstring JNICALL Java_com_example_cppquiz_Quiz_getOptionThree
  ( JNIEnv*   p_jenv
    , jobject   p_jthis
    , jlong     p_native_ptr
  )
{
  Question * ourQuestion = (Question*) p_native_ptr;
  Option * option = ourQuestion->getOptions()->at(2);
  string optionText = option->letter + ": " + option->theOption;
  return p_jenv->NewStringUTF(optionText.c_str());
}

JNIEXPORT extern "C" jstring JNICALL Java_com_example_cppquiz_Quiz_getOptionFour
  ( JNIEnv*   p_jenv
    , jobject   p_jthis
    , jlong     p_native_ptr
  )
{
  Question * ourQuestion = (Question*) p_native_ptr;
  Option * option = ourQuestion->getOptions()->at(3);
  string optionText = option->letter + ": " + option->theOption;
  return p_jenv->NewStringUTF(optionText.c_str());
}

JNIEXPORT extern "C" jchar JNICALL Java_com_example_cppquiz_Quiz_getCorrectOption
  ( JNIEnv* p_jenv
    , jobject p_jthis
    , jlong p_native_ptr
    )
{
  Question * ourQuestion = (Question*) p_native_ptr;
  return (jchar) ourQuestion->getCorrectLetter();
}

JNIEXPORT extern "C" jint JNICALL Java_com_example_cppquiz_Quiz_getQuizSize
  ( JNIEnv* p_jenv
    , jobject p_jthis
    , jlong p_native_ptr
  )
{
  Quiz * ourQuiz = (Quiz*) p_native_ptr;
  return (jint) ourQuiz->size;
}
