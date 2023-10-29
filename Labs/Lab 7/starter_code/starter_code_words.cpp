#include "starter_code_words.h"
#include <iostream>

int main() {
  char word1[10] = "ENGR";
  char word2[] = "151";
  char word3[] = "HeLLoWoRLD";
  char word4[] = "ILoveToCode";
  char word5[] = "helloworld";
  /***
      //test your code here
   ***/
  cout << word_length(word1) << word_length(word2) << word_length(word3)
       << word_length(word4) << word_length(word5);
  concatenate(word1, word2);
  int num_upper = 0, num_lower = 0;

  check_case(word3, num_upper, num_lower);
  cout << endl << word3 << endl << num_upper << endl << num_lower;
  return 0;
}
