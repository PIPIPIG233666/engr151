#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
  cout.precision(3);
  ifstream inF("init.txt");
  const double /*e = 2.718, */dt = 0.001;
  int T, ve;
  double M_fuel, M_n, M_total, vn = 0, M_payload;
  inF >> T >> ve >> M_total >> M_payload;
  inF.close();
  M_n = M_total;
  M_fuel = M_n - M_payload;
  while (M_fuel > 0) {
    M_fuel = M_n - M_payload;
    M_n -= (T * dt) / ve;
    vn += (T / M_n) * dt;
    // cout << "Mass is: "<<M_n<<" Mass of fuel is: "<<M_fuel<<" v_f is: "<<vn<<endl;
  }
  // << endl << M_payload;
  cout << vn;
  // M_payload = M_total * pow(1 / e, vn / ve);
  return 0;
}
