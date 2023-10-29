#include <iostream>
using namespace std;

/*
 * Starter code to obtain the nth element of the fibonacci sequence.
 */

int fib(int num) {
  // Recursive function to be completed
  //int prev = arr[i - 1], next = arr[i - 2];
  if (num <= 2)
    return num - 1;
  return fib(num - 1) + fib(num - 2);
}

int main() {
  // PLEASE DO NOT MAKE ANY CHANGES to the cout or cin statements below, they are
  // used by the autograder to compare outputs.
  int num = -1;
  cout << "which element of the fibonacci sequence would you like?\n";
  cin >> num;

  cout << "fib(" << num << "): " << fib(num) << "\n";
  ////////////////////////
}
