#include "exp_math.h"

long double exp_pow(double base, double exp) {
  long double result;
  if ((base < 0) && exp_fmod(exp, 1) != 0) {
    result = EXP_NAN;
  } else if (base == 0 && exp > 0) {
    result = 0;
  } else if (base == 0 && exp == 0) {
    result = 1;
  } else if (exp < 1 && exp > 0 && base > 1) {
    result = pow_to_one(base, exp);
  } else if (exp >= 1) {
    if (base < 0) {
      base = -base;
      result = pow_for(base, exp);
      if (exp_fmod(exp, 2) != 0) {
        result = -result;
      }
    } else {
      double exp_int = exp_floor(exp);
      double exp_div = exp - exp_int;
      long double part1 = pow_to_one(base, exp_div);
      long double part2 = pow_for(base, exp_int);
      result = part2 * part1;
    }
    if (result > EXP_DBL_MAX) {
      result = EXP_INFINITY;
    }
  } else {
    result = exp_exp(exp * exp_log(base));
  }
  return result;
}

long double pow_to_one(double base, double exp) {
  long double result = 1;
  if (exp == 0) {
    result = 1;
  } else {
    long double temp = 1;
    for (int i = 1; temp > EXP_EPS; i++) {
      temp = temp * exp * exp_log(base) / i;
      result = result + temp;
    }
  }
  return result;
}

long double pow_for(double base, double exp) {
  long double result = base;
  for (int i = 1; i < exp; i++) {
    result = result * base;
  }
  return result;
}
