#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
/***
Input: a string code
Modifies code to a string with the duplicates removed
with unique characters in the same order
as in the original string
e.g "aabccebce" -> "abcebce"**/

void remove_duplicates(string& code) {
  auto idx = 0;

  for (auto i = 0; i < static_cast<int>(code.size()) - 1; i++) {
    if (code[i] != code[i + 1]) {
      // Character is not the same as the next one, keep it
      code[idx++] = code[i];
    }
  }

  // Include the last character
  code[idx++] = code.back();

  // Resize the string to remove extra characters
  code.resize(idx);
}

/***
Input : a string code
Modifies code to a string with the "key" removed
key here can be the first 3 characters of the string
eg. popcorn -> corn
***/

void remove_key(string& code) {
  auto key = code.substr(0, 3);  // Extract the first 3 characters as the key

  auto pos = code.find(key);

  while (pos != string::npos) {
    code.erase(pos, 3);         // Erase the key from the string
    pos = code.find(key, pos);  // Find the next occurrence of the key
  }
}

/***
Input: a string code
Modifies code to a string with each character shifted 
up by 3 in the English alphabet
e.g. abc -> def
***/

void shift(string& code) {
  for (int i = 0; i < (int)code.size(); i++) {
    code.at(i) = (char)((int)code.at(i) + 3);
  }
}

/***
Input: a string c de
Output: returns a string where all spaces are replaced by
underscores

e.g. I want a holiday -> I_want_a_holiday
***/

string replace_space(string code) {
  for (int i = 0; i < (int)code.size(); i++) {
    if (code.at(i) == ' ')
      code.at(i) = '_';
  }
  return code;
}
