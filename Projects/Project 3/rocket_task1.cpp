#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
  ifstream inF("init.txt");
  const double /*e = 2.718, */dt = 0.0001;
  int T, v0 = 0, ve;
  double M_fuel, M_n, M_total, vn = v0, M_payload;
  inF >> T >> ve >> M_total >> M_payload;
  inF.close();
  M_n = M_total;
  M_fuel = M_n - M_payload;
  while (M_fuel >= 0) {
    M_n = M_n - (T * dt) / ve;
    M_fuel = M_n - M_payload;
    vn = vn + (T / M_n) * dt;
  }
  cout.precision(3);
  cout << vn;
  // << endl << M_payload;
  // M_payload = M_total * pow(1 / e, vn / ve);
  return 0;
}
