#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "process_command_line.hpp"
#include "radionuc.hpp"
#include "fluorine.hpp"

// TODO: Add any necessary #include statements!

using namespace std;

void test_case(int case_number);

int main(int argc, char* argv[]) {
    // Initialize a variable to store the test case to run
    int case_number = 0;
    // Call your function to process the command line arguments
    process_command_line(argc, argv, &case_number);
    // Call the specified test case
    test_case(case_number);
    // Return 0 on successful program completion
    return 0;
}

void test_case(const int case_number) {
    switch(case_number) {
    // Case 1:  Population of Fluorine18 nuclei decaying
    //          modeled with your radioNuclide class
    case 1: {
        const int N0 = 10000000; // Initial population size
        const double lambda = log(2.0) / (109.771 / 60.0); // Rate of decay
        const double tmax = 20; // End time of simulation (hours)
        const double dt = 0.01; // Time step of simulation (hours)
        double t = 0; // Current time of simulation (hours)
        radioNuclide F18(lambda,N0); // Construct population of Fluorine18 nuclei

        cout << "time\t N" << t << endl; // Print column headers
        while (t < tmax + dt) { // Loop while within defined simulation time
            cout << t << "\t" << F18; // Print time and population size
            cout << endl;
            F18.Decay(dt); // Decay the population
            t += dt; // Advance simulation time
        }
        break;
    }
    case 2: {
        const int N0 = 1000000; // Initial Mo population size
        const double lambdaMo = log(2.0) / 65.94; // Rate of decay for Mo
        const double lambdaTc = log(2.0) / 6.0067; // Rate of decay for Tc
        const double tmax = 100.0; // End time of simulation (hours)
        const double dt = 1.0; // Time step of simulation (hours)
        double t = 0.0; // Current time of simulation (hours)

        radioNuclide Mo99(lambdaMo, N0); // Construct population of Mo nuclei
        radioNuclide Tc99m(lambdaTc, 0); // Construct population of Tc nuclei

        const int outputEvery = 10; // Controls how often prints happen
        int counter = 0;
        cout << "t\tN (Tc99m)" << endl; // Print column headers
        while (t < tmax + dt) { // Loop while within defined simulation time
            if (!(counter % outputEvery)) { 
                cout << t << '\t' << Tc99m; // Print time and population of Tc
                cout << endl; 
            }
            Tc99m += Mo99.Decay(dt); // Decay Mo population, adding to the Tc population
            Tc99m.Decay(dt); // Decay Tc population
            t += dt; // Advance simulation time
        }
        break;
    }
    case 3: {
        const int N0 = 1000000; // Initial population size
        const double lambdaMo = log(2.0) / 65.94; // Rate of decay for Mo
        const double lambdaTc = log(2.0) / 6.0067; // Rate of decay for Tc
        const double tmax = 168.0; // hours in a week
        const double dt = 1.0;     // hours
        double t = 0.0;            // time

        radioNuclide Mo99(lambdaMo, N0); // Construct population of Mo nuclei
        radioNuclide Tc99m(lambdaTc, 0); // initially no Tc99m

        int ifextract = 1;                 // extraction counter of Tc-99m
        const double nHoursExtract = 12.0; // every 12 hours
        cout << "t\tN extracted" << endl; // Print column headers
        while (t < tmax + dt) { // Loop while within defined simulation time
            Tc99m += Mo99.Decay(dt); // Decay the Mo population, adding to the Tc population
            Tc99m.Decay(dt); // Decay the Tc population
            if (t >= nHoursExtract * ifextract) {
                ++ifextract;
                cout << t << '\t' << Tc99m; // Print time and number of Tc extracted
                cout << endl; 
                Tc99m.Zero(); // Extract the Tc population
            }
            t += dt; // Advance simulation time
        }
        break;
    }
    case 4: {
        const int N0 = 10000000;  // Initial population size
        const double tmax = 20.0; // hours
        const double dt = 0.01;   // hours
        double t = 0.0; // hours

        // Declare Fluorine-18 radioNuclide
        Fluorine18 F18(N0);

        cout << "time\t N" << t << endl; // Print column headers
        while (t < tmax + dt) // Loop while within defined simulation time
        {
            cout << t << "\t" << F18; // Print time and population size
            cout << endl; 
            F18.Decay(dt); // Decay Fluorine18 population
            t += dt; // Advance simulation time
        }
        break;
    }
    }
}