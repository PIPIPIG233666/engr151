// TODO: Implement derived Fluorine18 class
#include "radionuc.hpp"

class Fluorine18 : public radioNuclide {
 public:
  // inhenrit the public class members
  using radioNuclide::radioNuclide;
  // default constructors
  Fluorine18();
  Fluorine18(const int numNuc);
  double m_lamda = log(2.0) / (109.771 / 60.0);
};

Fluorine18::Fluorine18(){/*do nothing*/};

// assign the input to the inhenrited class lamda
Fluorine18::Fluorine18(const int numNuc) {
  radioNuclide(numNuc, Fluorine18::m_lamda);
}
