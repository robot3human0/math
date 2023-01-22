#include "exp_math.h"

long double exp_tan(double x) {
  long double result;
  result = exp_sin(x) / exp_cos(x);
  return result;
}
