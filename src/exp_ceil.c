#include "exp_math.h"

long double exp_ceil(double x) {
  double res;
  if (x == EXP_INFINITY || x == -EXP_INFINITY) {
    res = x;
  } else {
    long long int i;
    i = (long long int)x;
    if (x == LONG_MAX) {
      res = LONG_MAX;
    } else if (i < x) {
      res = i + 1;
    } else {
      res = i;
    }
  }
  return x != x ? EXP_NAN : res;
}
