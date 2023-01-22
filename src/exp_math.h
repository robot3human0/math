#ifndef _SRC_EXP_MATH_H_
#define _SRC_EXP_MATH_H_

#include <limits.h>
#include <stdio.h>

#define EXP_EPS 1e-25
#define EXP_PI 3.141592653589793238462643383279502884197169399375105820974944
#define EXP_NAN 0.0 / 0.0
#define EXP_INFINITY 1.0 / 0.0
#define EXP_e 2.7182818284590452353602874713527
#define EXP_DBL_MAX 1.79769313486231470e+308

int exp_abs(int x);
long double exp_acos(double x);
long double exp_asin(double x);
long double exp_atan(double x);
long double exp_ceil(double x);
long double exp_cos(double x);
long double exp_exp(double x);
long double exp_fabs(double x);
long double exp_floor(double x);
long double exp_fmod(double x, double y);
long double exp_log(double x);
long double exp_pow(double base, double exp);
long double exp_sin(double x);
long double exp_sqrt(double x);
long double exp_tan(double x);

long double atan_up_to_one(double x);
double norm_rad(double x);
long double pow_to_one(double base, double exp);
long double pow_for(double base, double exp);
double exp_fmax(double x, double y);

#endif  // _SRC_EXP_MATH_H_
