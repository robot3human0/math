#include "exp_math.h"

long double exp_floor(double num) {
  if (num == EXP_INFINITY || num == -EXP_INFINITY) return (num);
  long int tmp = num * 1000000;
  if ((tmp % 1000000 == 0 && (num < 0)) || (num == 0))
    return ((long long int)num);
  if (num != num)
    return EXP_NAN;
  else
    return (num > 0 ? (long long int)num : ((long long int)num) - 1);
}
