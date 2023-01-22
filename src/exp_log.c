#include "exp_math.h"

long double exp_log(double x) {
  long double ln = 0.0;
  if (x < 0 || x == -EXP_INFINITY) {
    ln = EXP_NAN;
  } else if (x < 2 && x != 0 && x != 1 && x > 0) {
    x--;
    long double temp = x;
    ln = x;
    for (int i = 2; exp_fabs(temp) > EXP_EPS; i++) {
      temp = temp * (-x) * (i - 1) / i;
      ln += temp;
    }
  } else if (x == 2) {
    ln = 0.6931471805599452862267640;
  } else if (x == 0) {
    ln = -EXP_INFINITY;
  } else if (x == 1) {
    ln = 0;
  } else if (x == EXP_INFINITY) {
    ln = EXP_INFINITY;
  } else {
    int n = 0;
    while (x > 2) {
      x /= 2;
      n++;
    }
    ln = exp_log(x) + n * exp_log(2);
  }
  return ln;
}
