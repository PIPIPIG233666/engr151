#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout.precision(3);
  ifstream inF("init.txt");
  // constants
  const double dt = 0.001, r_Earth = 6356, C_D = 0.500,
               A = 3.1415 * pow(6.6e-3 / 2, 2);
  int T;
  double M_fuel = 0, M_n=0, M_total=0, v_n = 0, M_payload=0, g_n=0, h_n = 0, v_esc=0, v_e=0,
                               roh_n=0;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    // append the lines to a vector
    lineVec.push_back(stod(line));
  }
  // close the input file
  inF.close();

  for (int i = 0; i < (int)lineVec.size(); i += 4) {
    // assign the vectors to corresponding variables
    T = lineVec[i];
    v_e = lineVec[i + 1];
    M_total = lineVec[i + 2];
    M_payload = lineVec[i + 3];

    // mass starts with fuel 
    M_n = M_total;
    // mass decreases by payload
    M_fuel = M_n - M_payload;
    roh_n = 1.225e6 * exp(-h_n / 9);
    bool exceed;
    while (v_n >= 0) {
      M_fuel = M_n - M_payload;
      M_n -= (T * dt) / v_e;

      // out of fuel
      // thrust is zero
      if (M_fuel <= 0)
        T = 0;

      // return early if escape velocity is exceeded
      exceed = v_esc < v_n;
      if (exceed) {
        cout << "Escape velocity reached";
        return 1;
      }

      // formulas from the spec
      h_n += v_n * dt;
      g_n = 3.962e5 / pow(h_n + r_Earth, 2);
      roh_n = 1.225e6 * exp(-h_n / 9);
      v_esc = sqrt(2 * g_n * (h_n + r_Earth));
      double airR = 1 / (2 * M_n) * roh_n * C_D * A * pow(v_n, 2);
      v_n += ((T / M_n) - g_n - airR) * dt;

      // testing output
      // cout << "v_n is: " << v_n << "\th_n is: " << h_n << "\tg_n is: " << g_n << "\tv_esc is: " << v_esc << endl;
    }
    cout << h_n;
    // cout << "Test " << (i / 4) + 1 << ": " << h_n << endl;
  }
  return 0;
}

