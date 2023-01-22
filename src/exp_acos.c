#include "exp_math.h"

long double exp_acos(double x) {
  long double result;
  result = EXP_PI / 2 - exp_asin(x);
  return result;
}
