#pragma once
#include <cmath>
#include <iostream>

using namespace std;

// TODO: Declare and implement radioNuclide class
class radioNuclide {
 private:
  // private members
  int m_numNuc;
  double m_lamda;

 public:
  // public members
  // default constructors
  radioNuclide();                                      // empty
  radioNuclide(const double lamda, const int numNuc);  // two arguments

  int Count();  // getter function for getting the private var m_numNuc
  int Decay(
      const double
          t_int);  // decaying function for updating the population by subtracting
  void Add(
      const int
          numNuc);  // adding function for adding negative values (decaying)
  void Zero();      // setter function for zeroing out population

  void operator+=(
      const int numNuc);  // overload function of +=, is equivlant to Add()
};

radioNuclide::radioNuclide() { /*do nothing*/
}

radioNuclide::radioNuclide(const double lamda, const int numNuc) {
  // assign values to private vars
  m_lamda = lamda;
  m_numNuc = numNuc;
}

int radioNuclide::Count() {
  // return the private population
  return m_numNuc;
};

int radioNuclide::Decay(const double t_int) {
  // Compute the probability for a single nucleus to decay
  double decayP = m_lamda * t_int;

  // Count the number of nuclei that decay
  int decayedCnt = 0;
  for (int i = 0; i < m_numNuc; i++) {
    // Generate a random number between 0 and 1
    double randNum = rand() / (double)RAND_MAX;

    // Compare with the decay probability
    if (randNum < decayP)
      decayedCnt++;
  }

  // Update the population size
  Add(-decayedCnt);

  // return the number of nuclei that decays
  return decayedCnt;
}

void radioNuclide::Add(const int numNuc) {
  // Adding input to the private population
  m_numNuc += numNuc;
};

void radioNuclide::Zero() {
  // Setting the private population to zero
  m_numNuc = 0;
};

void radioNuclide::operator+=(const int numNuc) {
  // Call Add() since it is the same function
  Add(numNuc);
};

// overload of << operator to output the getter
ostream& operator<<(ostream& os, radioNuclide& rNuc) {
  os << rNuc.Count();
  return os;
}
