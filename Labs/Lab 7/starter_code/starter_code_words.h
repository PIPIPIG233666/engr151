#include <iostream>
using namespace std;
/***
Function Decalarations
 ***/
int word_length(char []);
void concatenate(char [], char []);
void check_case(char [], int&, int&);
//word_length function
/***
A function that takes in a char-array and 
outputs the length of the word

TEST CASE EXAMPLE:
ILoveToCode has a word length of 11.

 ***/
int word_length(char word[]) {
  return -1;
}

/***
A function that concatenates two char-arrays together
The assumption in the word1 has "space" greater than 
the length of word1 and word2. eg. char word1[100]
can hold 100 characters and you would try to 
the length of both your words combined 
should be less than 100.

TEST CASE EXAMPLE:
If you concatenate ENGR and 151 together, you get ENGR151!
Can you also concatenate your lab section number onto this?
 ***/

void concatenate(char word1[], char word2[]) {
}

/***
A function that returns the number of upper case characters
and the number of lower case characters and modifies all upper
case characters in word to their corresponding lower case characters!
eg. SaNtA -> santa
TEST CASE EXAMPLE:

HeLLoWoRLD has 7 upper case and 3 lower case characters. 
 ***/
void check_case(char word[],int &num_upper, int &num_lower) {
}

