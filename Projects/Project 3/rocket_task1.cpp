#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout.precision(3);
  ifstream inF("init.txt");
  const double dt = 0.001;
  int T, v_e;
  double M_fuel, M_n, M_total, v_n = 0, M_payload;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    lineVec.push_back(stod(line));
  }

  T = lineVec[0];
  v_e = lineVec[1];
  M_total = lineVec[2];
  M_payload = lineVec[3];

  inF.close();
  M_n = M_total;
  M_fuel = M_n - M_payload;
  while (M_fuel > 0) {
    M_fuel = M_n - M_payload;
    M_n -= (T * dt) / v_e;
    v_n += (T / M_n) * dt;
  }
  cout << v_n;
  return 0;
}

