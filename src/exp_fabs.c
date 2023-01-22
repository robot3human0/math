#include "exp_math.h"

long double exp_fabs(double x) {
  if (x < 0) x *= -1;
  return x;
}
