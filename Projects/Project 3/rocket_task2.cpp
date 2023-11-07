#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout.precision(3);
  ifstream inF("init.txt");
  const double dt = 0.001, r_Earth = 6356;
  int T, ve;
  double M_fuel, M_n, M_total, vn = 0, M_payload, g_n, h_n;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    lineVec.push_back(stod(line));
  }
  inF.close();

  T = lineVec[0];
  ve = lineVec[1];
  M_total = lineVec[2];
  M_payload = lineVec[3];

  M_n = M_total;
  M_fuel = M_n - M_payload;
  g_n = 3.962e5 / pow(0 + r_Earth, 2);
  while (M_fuel > 0) {
    M_fuel = M_n - M_payload;
    M_n -= (T * dt) / ve;
    vn += ((T / M_n) - g_n) * dt;
    h_n += vn * dt;
    g_n = 3.962e5 / pow(h_n + r_Earth, 2);
  }
  cout << vn;
  return 0;
}

