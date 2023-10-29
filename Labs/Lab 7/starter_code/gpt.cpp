#include <iostream>

// Recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int n;
  std::cout << "Enter the number of Fibonacci terms to generate: ";
  std::cin >> n;

  if (n < 0) {
    std::cout << "Please enter a non-negative number." << std::endl;
    return 1;
  }

  std::cout << "Fibonacci sequence starting from 0: ";
  for (int i = 0; i < n; i++) {
    std::cout << fibonacci(i) << " ";
  }

  std::cout << std::endl;

  return 0;
}
