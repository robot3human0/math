#include "exp_math.h"

long double exp_exp(double x) {
  long double res = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (exp_fabs(res) > EXP_EPS) {
    res *= x / i;
    i += 1;
    temp += res;
    if (temp > EXP_DBL_MAX) {
      temp = EXP_INFINITY;
      break;
    }
  }
  if (flag == 1) {
    if (temp > EXP_DBL_MAX) {
      temp = 0;
    } else {
      temp = 1. / temp;
    }
  }
  if (temp > EXP_DBL_MAX) {
    return EXP_INFINITY;
  }
  return temp;
}
