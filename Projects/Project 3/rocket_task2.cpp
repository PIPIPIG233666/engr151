#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    cout.precision(3);
    ifstream inF("init.txt");
    const double dt = 0.001, r_Earth = 6356, ;
    int T, ve;
    double M_fuel, M_n, M_total, vn = 0, M_payload, g_n;

    // Read input values line by line
    string line;
    if (getline(inF, line)) {
        T = stoi(line);
    }
    if (getline(inF, line)) {
        ve = stoi(line);
    }
    if (getline(inF, line)) {
        M_total = stod(line);
    }
    if (getline(inF, line)) {
        M_payload = stod(line);
    }

    inF.close();
    M_n = M_total;
    M_fuel = M_n - M_payload;
    while (M_fuel > 0) {
        M_fuel = M_n - M_payload;
        M_n -= (T * dt) / ve;
        vn += ((T / M_n) - g_n) * dt;
      h_n += v_n*dt;
      g_n = 3.962e5/(h_n+r_Earth);
    }
    cout << vn;
    return 0;
}
