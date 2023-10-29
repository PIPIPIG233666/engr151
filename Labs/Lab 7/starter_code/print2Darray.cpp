#include <cmath>
#include <iostream>

using namespace std;

const int M = 15;
const int N = 21;

/*DECLARE YOUR PRINT FUNCTION HERE*/
void print_array(char arr[M][N]);

int main() {

  //creating test array
  char arr[M][N];
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i > 2 && i < 7 && ((j > 5 && j < 9) || (j > 10 && j < 14))) {
        arr[i][j] = '!';
      } else if ((i < 14 && i > 8) &&
                 (sqrt(pow(i - 5, 2) + pow(j - 10, 2)) < 7)) {
        arr[i][j] = '8';
      } else if (sqrt(pow(i - 7, 2) + pow(j - 10, 2)) < 8) {
        arr[i][j] = '*';
      } else {
        arr[i][j] = ' ';
      }
    }
  }

  /*CALL YOUR PRINT FUNCTION HERE*/
  print_array(arr);

  return 0;
}

/*DEFINE YOUR PRINT FUNCTION HERE*/
void print_array(char arr[M][N]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
