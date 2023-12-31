#include <iostream>

using namespace std;

int main() {
  /*
   * F(0) = 0
   * F(1) = 1
   * F(n) = F(n-1) + F(n-2)
   */
  // Initialize the array to be 2048 elements, and the first and second being 0
  // and 1
  int arr[2048] = {0, 1};
  // Initialize the user input to be 0
  int n = 0;
  printf("how many fibonacci numbers do you want printed?");
  cin >> n;
  // implement fib using while loop
  // Initialize the counter to be zero
  int i = 0;
  while (i < n) {
    if (i > 1) {
      // Only do things with n if the n i greater than 1
      int prev = arr[i - 1], next = arr[i - 2];
      arr[i] = prev + next;
    }
    printf("%d ", arr[i]);
    i++;
  }
}
