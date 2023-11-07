#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/*
 * calculates the V at n (final)
 * returns double
 */
double getV_n();

double getV_n() {
  ifstream inF("init.txt");
  // dt is constant and should not change
  const double dt = 0.001;
  int T;
  double M_fuel, M_n, M_total, v_n = 0, M_payload, v_e;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    // append the lines to a vector
    lineVec.push_back(stod(line));
  }
  // close the input file
  inF.close();

  // assign the vectors to corresponding variables
  T = lineVec[0];
  v_e = lineVec[1];
  M_total = lineVec[2];
  M_payload = lineVec[3];

  // mass starts with fuel + rocket
  M_n = M_total;
  // mass decreases by payload
  M_fuel = M_n - M_payload;
  // keep the loop running until there is no fuel
  while (M_fuel > 0) {
    M_fuel = M_n - M_payload;
    // formulas from the spec
    M_n -= (T * dt) / v_e;
    v_n += (T / M_n) * dt;
  }
  return v_n;
}

int main() {
  cout.precision(3);
  cout << getV_n();
  return 0;
}
