#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  cout.precision(3);
  ifstream inF("init.txt");
  const double dt = 0.001;
  int T, v_e;
  double M_fuel, M_n, M_total, v_n = 0, M_payload;
  int cnt = 0;
  string line;
  while (getline(inF, line)) {
    ++cnt;
  }

  // Reset file pointer to beginning
  inF.clear();
  inF.seekg(0, ios::beg);

  for (int i = 0; i < cnt / 4; i++) {
    inF >> T >> v_e >> M_total >> M_payload;
    inF.close();
    M_n = M_total;
    M_fuel = M_n - M_payload;
    while (M_fuel > 0) {
      M_fuel = M_n - M_payload;
      M_n -= (T * dt) / v_e;
      v_n += (T / M_n) * dt;
    }
    cout << v_n;
  }
  return 0;
}

