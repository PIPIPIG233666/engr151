// TODO: Implement derived Fluorine18 class
#include "radionuc.hpp"

class Fluorine18 : public radioNuclide {
 public:
  // inhenrit the public class members
  using radioNuclide::radioNuclide;
  // default constructors
  Fluorine18();
  Fluorine18(const int numNuc);

 private:
  static const double m_lamda;
};

const double Fluorine18::m_lamda = log(2.0) / (109.771 / 60.0);

Fluorine18::Fluorine18(){/*do nothing*/};

// assign the input to the inhenrited class's private lamda
Fluorine18::Fluorine18(const int numNuc)
    : radioNuclide(Fluorine18::m_lamda, numNuc) {}
