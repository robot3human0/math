#include "exp_math.h"

long double exp_sqrt(double x) {
  double mid;
  if (x < 0 || x != x) {
    mid = EXP_NAN;
  } else {
    double left = 0, right = exp_fmax(1, x);
    mid = (left + right) / 2;
    for (int i = 1; ((mid - left) > EXP_EPS) && (i < 10000); i++) {
      if (mid * mid > x)
        right = mid;
      else
        left = mid;
      mid = (left + right) / 2;
    }
  }
  return mid;
}

double exp_fmax(double x, double y) {
  double res;
  if (x >= y)
    res = x;
  else
    res = y;
  return res;
}
