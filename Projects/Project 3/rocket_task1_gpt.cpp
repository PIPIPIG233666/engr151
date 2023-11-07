#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    double T, v_e, Mtotal, Mpayload;
    std::ifstream infile("init.txt");
    infile >> T >> v_e >> Mtotal >> Mpayload;

    double v = 0;
    double M = Mtotal;
    double delta_t = 0.001; // You can adjust this time step as needed

    while (M > Mpayload) {
        v += T / M * delta_t;
        M -= T * delta_t / v_e;
    }

    std::cout.precision(3);
    std::cout << v << std::endl;

    return 0;
}

