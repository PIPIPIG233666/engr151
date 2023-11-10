#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
double getH_n(double T, double v_e, double M_total, double M_payload) {
  // constants
  const double dt = 0.001, r_Earth = 6356, C_D = 0.500,
               A = 3.1415 * pow(6.6e-3 / 2, 2);
  double M_fuel = 0, M_n = 0, v_n = 0, g_n = 0, h_n = 0, v_esc = 0, roh_n = 0;
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
      return 1;
    }

    // formulas from the spec
    h_n += v_n * dt;
    g_n = 3.962e5 / pow(h_n + r_Earth, 2);
    roh_n = 1.225e6 * exp(-h_n / 9);
    v_esc = sqrt(2 * g_n * (h_n + r_Earth));
    double airR = 1 / (2 * M_n) * roh_n * C_D * A * pow(v_n, 2);
    v_n += ((T / M_n) - g_n - airR) * dt;
  }
  return h_n;
}

int main() {
  cout.precision(3);
  ifstream inF("init_opt.txt");
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    // append the lines to a vector
    lineVec.push_back(stod(line));
  }
  // close the input file
  inF.close();

  // for (int i = 0; i < (int)lineVec.size(); i += 4) {
  // double o =
  // getH_n(lineVec[i], lineVec[i + 1], lineVec[i + 2], lineVec[i + 3]);
  // cout << "Test " << (i / 4) + 1 << ": " << o << endl;
  // }
  int i = 0;
  const double h_tar = 2000;
  double M_fuel_max = lineVec[i] / 0.00981 - lineVec[i + 2], M_fuel_min = 0,
         M_fuel = M_fuel_min;
  double h = getH_n(lineVec[i], lineVec[i + 1], M_fuel, lineVec[i + 2]);
  cout << h<<endl;
  cout << M_fuel_max << endl;
  // if (h < h_tar) {
    // cout << "Rocket too heavy";
    // return 1;
  // }
  if (h == 1) {
    cout << "Escape velocity reached";
  }
  double err = abs(h - h_tar);
  const double err_max = 0.2 / 100 * h_tar;
  while (err > err_max) {
    if (err > 50) {
      if (err > err_max)
        M_fuel += 25;
      else
        M_fuel -= 25;
    } else {
      if (err > err_max)
        M_fuel += 5;
      else
        M_fuel -= 5;
    }

    h = getH_n(lineVec[i], lineVec[i + 1], M_fuel, lineVec[i + 2]);
err = abs(h - h_tar);

    cout << "fuel " << M_fuel << " at height diff " << err << endl;
  }
  cout << M_fuel-250;

  return 0;
}

