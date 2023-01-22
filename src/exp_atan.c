#include "exp_math.h"

long double exp_atan(double x) {
  long double result = x;
  if (x < 1.0 && x > -1.0) {
    result = atan_up_to_one(x);
  } else if (x == 1) {
    result = EXP_PI / 4;
  } else if (x == -1) {
    result = -EXP_PI / 4;
  } else if (x > 1) {
    result = EXP_PI / 2 - atan_up_to_one(1 / x);
  } else if (x < -1) {
    result = -EXP_PI / 2 - atan_up_to_one(1 / x);
  }
  return result;
}

long double atan_up_to_one(double x) {
  long double result = x;
  long double temp = x;
  for (int i = 1; exp_fabs(temp) > EXP_EPS; i++) {
    temp = exp_pow(-1, i) * exp_pow(x, 2 * i + 1) / (2 * i + 1);
    result = result + temp;
  }
  return result;
}
