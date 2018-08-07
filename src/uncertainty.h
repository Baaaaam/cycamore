#ifndef CYCLASS_SRC_UNCERTAINTY_H_
#define CYCLASS_SRC_UNCERTAINTY_H_

#include <random>
#include "cyclus.h"

namespace cycamore {

double get_corrected_param(int param, double uncertainty);
double get_corrected_param(double param, double uncertainty);

}

#endif  // CYCLASS_SRC_UNCERTAINTY_H_

