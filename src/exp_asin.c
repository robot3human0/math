#include "exp_math.h"

long double exp_asin(double x) {
  long double result = x;
  if (x < 1.0 && x > -1.0) {
    result = exp_atan(x / exp_sqrt(1 - x * x));
  } else if (x == 1) {
    result = EXP_PI / 2;
  } else if (x == -1) {
    result = -EXP_PI / 2;
  } else if (x > 1 || x < -1) {
    result = EXP_NAN;
  }
  return result;
}
