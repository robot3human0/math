#include "exp_math.h"

long double exp_sin(double x) {
  long double result;
  if (x == EXP_INFINITY || x == -EXP_INFINITY || x != x) {
    result = EXP_NAN;
  } else {
    x = norm_rad(x);
    result = x;
    long double temp = x;
    for (int i = 1; exp_fabs(temp) > EXP_EPS; i++) {
      temp = temp * (-1) * exp_pow(x, 2) / (2 * i * (2 * i + 1));
      result = result + temp;
    }
  }
  return result;
}

double norm_rad(double x) {
  while (x > EXP_PI) {
    x = x - 2 * EXP_PI;
  }
  while (x < -EXP_PI) {
    x = x + 2 * EXP_PI;
  }
  return x;
}
