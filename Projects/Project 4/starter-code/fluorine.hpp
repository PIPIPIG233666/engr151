// TODO: Implement derived Fluorine18 class
#include <cmath>
#include "radionuc.hpp"

class Fluorine18 : public radioNuclide {
 public:
  using radioNuclide::radioNuclide;
  Fluorine18();
  Fluorine18(const int numNuc);
  double m_lamda = log(2.0) / (109.771 / 60.0);

 private:
};

Fluorine18::Fluorine18(){};

Fluorine18::Fluorine18(const int numNuc){
    radioNuclide(numNuc, Fluorine18::m_lamda);
}
