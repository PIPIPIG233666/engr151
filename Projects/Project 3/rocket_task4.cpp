#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/*
 * calculates the h at n (final)
 * @M_total - total mass of rocket to test
 * returns double
 */
double getH_n(double M_total);

double getH_n(double M_total) {
  ifstream inF("init_opt.txt");
  // more constats
  const double dt = 0.001, r_Earth = 6356, C_D = 0.500,
               A = 3.1415 * pow(6.6e-3 / 2, 2);
  int T;
  double M_fuel, M_n, v_n = 0, M_payload, g_n, h_n = 0, v_esc, v_e, roh_n;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    // append the lines to a vector
    lineVec.push_back(stod(line));
  }
  // close the input file
  inF.close();

  for (int i = 0; i < (int)lineVec.size(); i += 3) {
    // assign the vectors to corresponding variables if the init.txt has multiple inputs
    T = lineVec[i];
    v_e = lineVec[i + 1];
    M_payload = lineVec[i + 2];

    // mass starts with fuel + rocket
    M_n = M_total;
    // mass decreases by payload
    M_fuel = M_n - M_payload;
    roh_n = 1.225e6 * exp(-h_n / 9);
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
      g_n = 3.962e5 / pow(h_n + r_Earth, 2);  // Recalculate g_n
      roh_n = 1.225e6 * exp(-h_n / 9);
      v_esc = sqrt(2 * g_n * (h_n + r_Earth));
      double airR = 1 / (2 * M_n) * roh_n * C_D * A * pow(v_n, 2);
      v_n += ((T / M_n) - g_n - airR) * dt;

      // testing output
      // cout << "v_n is: " << v_n << "\th_n is: " << h_n << "\tg_n is: " << g_n << "\tv_esc is: " << v_esc << endl;
    }
    // cout << "Test " << (i / 4) + 1 << ": " << h_n << endl;
  }
  return h_n;
}

int main() {
  cout.precision(3);
  double testFuel = 2000;
  while (getH_n(testFuel) != 2005 || getH_n(testFuel) != 1995) {
    if (getH_N(testFuel) < 2000) {
      cout << ""
    }
  }
  return 0;
}
