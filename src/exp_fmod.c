#include "exp_math.h"

long double exp_fmod(double x, double y) {
  y = exp_fabs(y);
  long double res = exp_fabs(x);
  if (x != x) return EXP_NAN;
  if (x == EXP_INFINITY || x == -EXP_INFINITY) {
    res = x;
  } else {
    for (int i = 0; res >= y; i++) res = res - y;
    res = x < 0. ? res * -1. : res;
  }
  return res;
}
