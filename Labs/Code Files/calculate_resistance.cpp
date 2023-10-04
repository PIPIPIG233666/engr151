//ENGR 151 Lab 5 Exercise 1

//include necessary libraries
#include <iostream>

using namespace std;

// This program calculates the resistance (in Ohms) of a cylindrical wire given:
// 	1. the length of the wire in meters
// 	2. the radius of the wire in millimeters
// 	3. and the resistivity of the wire's material given in (Ohm-m)

int main()
{
    double length = 0;
    double radius = 0; 
    double resistivity = 0;
    cout << "Enter the length of the wire(m): ";
    cin >> length;
    cout << endl << "Enter the radius of the wire(mm): ";
    cin >>  radius;
    cout << endl << "Enter the resistivity of the wire(Ohm*m): ";
    cin >> resistivity;
    cout << endl;

    double pi = 3.14159;

    double cross_sectional_area = pi * radius * radius * 1e-6;

    double resistance = (resistivity * legth) / cross_sectional_area
    
    cout << "The resistance of the wire is: " << resistance << " Ohms" << endl;

    return 0;
}
