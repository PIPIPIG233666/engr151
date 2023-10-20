#include <iostream>

using namespace std;

int main() {
  /*
   * F(0) = 0
   * F(1) = 1
   * F(n) = F(n-1) + F(n-2)
   */
  // Initialize the array to be 2048 elements, and the first and second being 0 and 1
  int arr[2048] = {0, 1};
  // Initialize the user input to be 0
  int n = 0;
  // Print out the message for user input
  printf("how many fibonacci numbers do you want printed?\n");
  cin >> n;
  // implement fib using for loop
  for (int i = 0; i < n; i++) {
    if (i > 1) {
      // Only do things with n if the n i greater than 1
      int prev = arr[i - 1], next = arr[i - 2];
      arr[i] = prev + next;
    }
    printf("%d ", arr[i]);
  }
}
