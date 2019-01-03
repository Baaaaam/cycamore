#include "uncertainty.h"

namespace cycamore {

double get_corrected_param(double param, double param_uncertainty) {
  if (param_uncertainty == 0) {
    return param;
  } else {
    std::default_random_engine de(std::clock());
    std::normal_distribution<double> nd(param, param * param_uncertainty);
    double val = nd(de);
    return val;
  }
}
double get_corrected_param(int param, double param_uncertainty) {
  if (param_uncertainty == 0) {
    return param;
  } else {
    std::default_random_engine de(std::clock());
    std::normal_distribution<double> nd(param, param * param_uncertainty);
    double val_tmp = nd(de);
    double val = std::lround(val_tmp);
    return val;
  }
}
}
