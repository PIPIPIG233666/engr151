#include <iostream>
#include <string>

using namespace std;

int main() {
  int c = 0;
  int q = 0;
  int d = 0;
  int n = 0;
  int p = 0;

  // Write your code here
  const int valQ = 25, valD = 10, valN = 5, valP = 1;

  string in;
  cin >> in;

  auto periodPos = in.find(".");
  int numDo, numCe;
  if (periodPos != string::npos) {
    numDo = stoi(in.substr(0, periodPos));
    numCe = stoi(in.substr(periodPos + 1));
  }
  numDo *= 100;
  numDo /= valQ;

  q = numDo;

  int mod = numCe % valQ;
  if (mod > 0)
    q += numCe / valQ;

  if (mod > valD) {
    d = mod / valD;
    mod %= valD;
  } else {
    n = mod / valN;
    d = 0;
    mod %= valN;

    p = mod / valP;
  }
  if (mod > valN) {
    n = mod / valN;
    mod %= valN;
  }
  if (mod >= valP) {
    p += mod / valP;
  }
  c = q + d + n + p;

  // Please do not make any changes to the statement below.
  cout << c << " coins: " << q << " Quarters, " << d << " Dimes, " << n
       << " Nickels, " << p << " Pennies." << endl;
  return 0;
}
