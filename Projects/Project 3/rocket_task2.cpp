#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout.precision(3);
  ifstream inF("init.txt");
  const double dt = 0.001, r_Earth = 6356;
  int T;
  double M_fuel, M_n, M_total, v_n = 0, M_payload, g_n, h_n = 0, v_esc, v_e;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    lineVec.push_back(stod(line));
  }
  inF.close();

  for (int i = 0; i < (int)lineVec.size(); i += 4) {
    T = lineVec[i];
    v_e = lineVec[i + 1];
    M_total = lineVec[i + 2];
    M_payload = lineVec[i + 3];

    M_n = M_total;
    M_fuel = M_n - M_payload;
    bool exceed;
    while (v_n >= 0) {
      M_fuel = M_n - M_payload;
      M_n -= (T * dt) / v_e;

      // out of fuel
      // thrust is zero
      if (M_fuel <= 0)
        T = 0;

      exceed = v_esc <= v_n;
      if (exceed) {
        cout << "Escape velocity reached";
        return 1;
      }

      h_n += v_n * dt;
      g_n = 3.962e5 / pow(h_n + r_Earth, 2);  // Recalculate g_n
      v_esc = sqrt(2 * g_n * (h_n + r_Earth));

      v_n += ((T / M_n) - g_n) * dt;

      // testing output
      // cout << "v_n is: " << v_n << "\th_n is: " << h_n << "\tg_n is: " << g_n << "\tv_esc is: " << v_esc << endl;
    }
    cout << "Test " << (i / 4) + 1 << ": " << h_n << endl;
    v_n = 0;  // Reset velocity for next test case
    h_n = 0;  // Reset height for next test case
  }
  return 0;
}

