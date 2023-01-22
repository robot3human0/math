#include "exp_math.h"

long double exp_cos(double x) {
  long double result;
  if (x == EXP_INFINITY || x == -EXP_INFINITY || x != x) {
    result = EXP_NAN;
  } else {
    x = norm_rad(x);
    result = 1;
    if (x == EXP_PI / 2 || x == -EXP_PI / 2) {
      result = 0;
    } else {
      long double temp = 1;
      for (int i = 1; exp_fabs(temp) > EXP_EPS; i++) {
        temp = temp * (-1) * exp_pow(x, 2) / ((2 * i - 1) * 2 * i);
        result = result + temp;
      }
    }
  }
  return result;
}
