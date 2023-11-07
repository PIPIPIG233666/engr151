#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/*
 * calculates the h at n (final)
 * returns double
 */
double getH_n();

double getH_n() {
  ifstream inF("init.txt");
  // dt and radius of earth are constant and should not change
  const double dt = 0.001, r_Earth = 6356;
  int T;
  double M_fuel, M_n, M_total, v_n = 0, M_payload, g_n, h_n = 0, v_esc, v_e;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    // append the lines to a vector
    lineVec.push_back(stod(line));
  }
  // close the input file
  inF.close();

  for (int i = 0; i < (int)lineVec.size(); i += 4) {
    // assign the vectors to corresponding variables if the init.txt has multiple inputs
    T = lineVec[i];
    v_e = lineVec[i + 1];
    M_total = lineVec[i + 2];
    M_payload = lineVec[i + 3];

    // mass starts with fuel + rocket
    M_n = M_total;
    // mass decreases by payload
    M_fuel = M_n - M_payload;
    bool exceed;
    // keep the loop running until the velocity is no longer positive
    while (v_n >= 0) {
      M_fuel = M_n - M_payload;
      M_n -= (T * dt) / v_e;

      // out of fuel
      // thrust is zero
      if (M_fuel <= 0)
        T = 0;

      exceed = v_esc <= v_n;
      // return 1 early if exceeds
      if (exceed) {
        cout << "Escape velocity reached";
        return 1;
      }

      // formulas from the spec
      h_n += v_n * dt;
      g_n = 3.962e5 / pow(h_n + r_Earth, 2);
      v_esc = sqrt(2 * g_n * (h_n + r_Earth));

      v_n += ((T / M_n) - g_n) * dt;

      // testing output
      // cout << "v_n is: " << v_n << "\th_n is: " << h_n << "\tg_n is: " << g_n << "\tv_esc is: " << v_esc << endl;
    }
    // cout << "Test " << (i / 4) + 1 << ": " << h_n << endl;
  }
  return h_n;
}

int main() {
  cout.precision(3);

  cout << getH_n();
  return 0;
}
