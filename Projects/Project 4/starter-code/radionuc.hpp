#pragma once
#include <iostream>
#include <cmath>

using namespace std;

// TODO: Declare and implement radioNuclide class
class radioNuclide {
 private:
  int m_numNuc;
  double m_lamda;

 public:
  radioNuclide();
  radioNuclide(const double lamda, const int numNuc);
  int Count();
  int Decay(const double t_int);
  void Add(const int numNuc);
  void Zero();
  void operator+=(const int numNuc);
};

radioNuclide::radioNuclide() {}

radioNuclide::radioNuclide(const double lamda, const int numNuc) {
  m_lamda = lamda;
  m_numNuc = numNuc;
}

int radioNuclide::Count() {
  return m_numNuc;
};

int radioNuclide::Decay(const double t_int) {
  // Compute the probability for a single nucleus to decay
  double decayP = 1 - exp(-m_lamda * t_int);

  // Cnt the number of nuclei that decay
  int decayedCnt = 0;
  for (int i = 0; i < m_numNuc; i++) {
    // Generate a random number between 0 and 1
    double randNum = rand() / (double)RAND_MAX;

    // Compare with the decay probability
    if (randNum < decayP) {
      decayedCnt++;
    }
  }

  // Update the population size
  Add(-decayedCnt);

  return decayedCnt;
}

void radioNuclide::Add(const int numNuc) {
  m_numNuc += numNuc;
};

void radioNuclide::Zero() {
  m_numNuc = 0;
};

void radioNuclide::operator+=(const int numNuc) {
  Add(numNuc);
};

ostream& operator<<(ostream& os, radioNuclide& rNuc) {
  os << rNuc.Count();
  return os;
}
