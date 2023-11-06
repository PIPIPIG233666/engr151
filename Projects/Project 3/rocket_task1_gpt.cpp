#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    // Read input values from the "init.txt" file.
    std::ifstream inputFile("init.txt");
    double T, ve, Mtotal, Mpayload;
    inputFile >> T >> ve >> Mtotal >> Mpayload;
    inputFile.close();

    // Define constants and initial values.
    double v_initial = 0.0;  // Initial velocity
    double M_current = Mtotal;  // Current mass of the rocket

    // Constants
    // const double euler = 2.718;  // Euler's number
    const double delta_t = 0.0001;  // Time step in seconds

    // Perform the simulation until there is no fuel left (M_current > Mpayload).
    while (M_current > Mpayload) {
        // Calculate the change in velocity (delta_v) using the rocket equation.
        double delta_v = T / M_current * delta_t;

        // Update the velocity using the calculated delta_v.
        v_initial += delta_v;

        // Update the mass of the rocket for the next iteration.
        M_current -= T * delta_t / ve;
    }

    // The final velocity is now stored in v_initial.
    std::cout.precision(3);  // Set output precision to three significant figures.
    std::cout << v_initial << std::endl;  // Print the final velocity.

    return 0;
}

